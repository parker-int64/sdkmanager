#include "appcontroller.h"
#include <QCoreApplication>
#include <QProcess>
#ifdef Q_OS_WIN
#include <windows.h>
#endif

AppController::AppController(QObject *parent) : QObject(parent)
{
}

AppController::~AppController()
{
}

void AppController::restartApp()
{
    QCoreApplication::quit();
    QProcess::startDetached(QCoreApplication::applicationFilePath(), QCoreApplication::arguments());
}

void AppController::closeApp()
{
    QCoreApplication::quit();
}

void AppController::getSysInfo()
{
    QString platform;
    QString cpuInfo;
    QString memoryInfo;
    QString storageInfo;

#ifdef Q_OS_WIN
    platform = "Windows";

    // Windows-specific code to get CPU and memory/storage info
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    cpuInfo = QString("Processor Architecture: %1, Number of Processors: %2")
                  .arg(sysInfo.wProcessorArchitecture)
                  .arg(sysInfo.dwNumberOfProcessors);

    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(memStatus);
    if (GlobalMemoryStatusEx(&memStatus))
    {
        memoryInfo = QString("Total Physical Memory: %1 MB, Available Physical Memory: %2 MB")
                         .arg(memStatus.ullTotalPhys / (1024 * 1024))
                         .arg(memStatus.ullAvailPhys / (1024 * 1024));
    }

    ULARGE_INTEGER freeBytesAvailable, totalBytes, totalFreeBytes;
    if (GetDiskFreeSpaceEx(NULL, &freeBytesAvailable, &totalBytes, &totalFreeBytes))
    {
        storageInfo = QString("Total Storage: %1 GB, Free Storage: %2 GB")
                          .arg(totalBytes.QuadPart / (1024 * 1024 * 1024))
                          .arg(totalFreeBytes.QuadPart / (1024 * 1024 * 1024));
    }
#elif defined(Q_OS_MAC)
    platform = "MacOS";
#elif defined(Q_OS_LINUX)
    platform = "Linux";
#else
    platform = "Unknown";
#endif

#if defined(Q_OS_LINUX) || defined(Q_OS_MAC)
    // Linux/MacOS-specific code to get CPU and memory/storage info
    QFile cpuFile("/proc/cpuinfo");
    if (cpuFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&cpuFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            if (line.startsWith("model name"))
            {
                cpuInfo = line.section(':', 1).trimmed();
                break;
            }
        }
        cpuFile.close();
    }

    QFile memFile("/proc/meminfo");
    if (memFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&memFile);
        QString totalMem, freeMem;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            if (line.startsWith("MemTotal"))
            {
                totalMem = line.section(':', 1).trimmed();
            }
            else if (line.startsWith("MemAvailable"))
            {
                freeMem = line.section(':', 1).trimmed();
            }
            if (!totalMem.isEmpty() && !freeMem.isEmpty())
            {
                memoryInfo = QString("Total Memory: %1, Available Memory: %2").arg(totalMem, freeMem);
                break;
            }
        }
        memFile.close();
    }

    QStorageInfo storage = QStorageInfo::root();
    storageInfo = QString("Total Storage: %1 GB, Free Storage: %2 GB")
                      .arg(storage.bytesTotal() / (1024 * 1024 * 1024))
                      .arg(storage.bytesFree() / (1024 * 1024 * 1024));
#endif

    qDebug() << "Platform:" << platform;
    qDebug() << "CPU Info:" << cpuInfo;
    qDebug() << "Memory Info:" << memoryInfo;
    qDebug() << "Storage Info:" << storageInfo;
}
