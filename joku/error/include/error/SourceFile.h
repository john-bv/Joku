#pragma once

#include <string>
#include <vector>

namespace joku::error
{
    namespace LF
    {
        enum LineFeed
        {
            CRLF,
            LF
        };
    };

    struct SourceLine
    {
        long offset;
        // The length of the line.
        long length;
        // The chars contained in that line
        char *chars;
    };

    class SourceFile
    {
        private:
            std::vector<SourceLine> lines;
            // ending linefeed type
            LF::LineFeed lf;
            // The length of the file.
            long length;
        public:
            SourceFile(std::vector<SourceLine> lines, LF::LineFeed lf, long length);

            static SourceFile *from_str(char* str, long len);
            static SourceFile *from_str(std::string *str);
    };
}