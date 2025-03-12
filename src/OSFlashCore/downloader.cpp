#include "downloader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "spdlog/spdlog.h"
#include <iomanip>

Downloader::Downloader(const std::string &url, const std::string &filename)
{
#ifdef _DEBUG
    spdlog::set_level(spdlog::level::debug);
#endif
}

bool Downloader::invokeDownload(const std::string &url, const std::string &filename)
{
    return false;
}

bool Downloader::validCheckSum(const std::string &filename, const std::string &checksum, int checkSumType)
{
    return false;
}

std::string Downloader::calcSHA256(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if ( !file.is_open() ) {
        spdlog::error("Unable to open the file {}", filename);
        // TODO: IMPLEMENT EXCEPTION HANDLING
    }

    SHA256_CTX sha256Context;

    SHA256_Init(&sha256Context);

    const size_t bufferSize = 8192;
    char buffer[bufferSize];

    while( file.read(buffer, bufferSize) || file.gcount() ) {
        SHA256_Update(&sha256Context, buffer, file.gcount());
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_Final(hash, &sha256Context);

    std::ostringstream hexStream;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        hexStream << std::setw(2) << std::setfill('0') << std::hex << (int)hash[i];
    }

#ifdef _DEBUG
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("Filename: {}\n SHA256-HASH: {}", filename, hexStream.str());
#endif

    return hexStream.str();
}
