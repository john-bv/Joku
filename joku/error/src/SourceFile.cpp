#include "error/SourceFile.h"

using namespace joku::error;

SourceFile::SourceFile(std::vector<SourceLine> lines, LF::LineFeed lf, long length)
{
    this->lines = lines;
    this->lf = lf;
    this->length = length;
}

SourceFile *SourceFile::from_str(char *str, long len)
{
    // we need to make a new source file from lines
    // get each line from the string
    std::vector<SourceLine> lines;
    // the current line
    SourceLine line = SourceLine { 0, 0, nullptr };

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '\n')
        {
            // add the line to the vector
            lines.push_back(line);
            // reset the line
            line = SourceLine { 0, 0, nullptr };
        }
        else
        {
            // add the char to the line
            line.chars[line.length] = str[i];
            // increment the length
            line.length++;
        }
    }

    return new SourceFile(lines, LF::LF, len);
}

SourceFile *SourceFile::from_str(std::string *str)
{
    return SourceFile::from_str((char *)str->c_str(), (long) str->length());
}