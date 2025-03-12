#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <string>

#include <openssl/sha.h>
class Downloader
{
private:
    std::string m_url;
    std::string m_filename;
    enum CHECKSUMTYPE {
        md5 = 0,
        sha256 = 1,
    };
public:
    Downloader() = default; /* Default constructor */
    Downloader(const std::string &url, const std::string &filename);

    bool invokeDownload(const std::string &url, const std::string &filename);

    /// @brief Compare if the checksums are matched
    /// @param filename 
    /// @param checksum 
    /// @param checkSumType 
    /// @return 
    bool validCheckSum(const std::string &filename, const std::string &checksum, int checkSumType = CHECKSUMTYPE::sha256);

    /// @brief Calculate SHA256 hash of a file
    /// @param filename input file name (a full path included)
    /// @return file SHA256 hash
    std::string calcSHA256(const std::string &filename);

    /* Default deconstructor */
    ~Downloader() = default;
};



#endif // DOWNLOADER_H
