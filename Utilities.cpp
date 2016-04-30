/* Author:          Matthew James Harrison
 * Class:           CSI-240-04
 * Date Updated:    April 29, 2016
 *
 * Description:
 *    A custom namespace for utility functions.
 *
 * Certification of Authenticity:
 *    I certify that this is entirely my own work, except where I have given
 *    fully - documented references to the work of others. I understand the
 *    definition and consequences of plagiarism and acknowledge that the assessor
 *    of this assignment may, for the purpose of assessing this assignment:
 *      -   Reproduce this assignment and provide a copy to another member of
 *          academic staff; and/or
 *      -   Communicate a copy of this assignment to a plagiarism checking
 *          service (which may then retain a copy of this assignment on its
 *          database for the purpose of future plagiarism checking)
 ******************************************************************************/

#include "Utilities.h"

/* Purpose:  Clear console
 *     Pre:  None
 *    Post:  Console cleared
 *  Source:  http://www.cplusplus.com/forum/beginner/3207/
 ******************************************************************************/
void utls::clear()
{
    std::cout << std::string(100, '\n');
}

/* Purpose:  Clear console via system call
 *     Pre:  None
 *    Post:  Console cleared
 ******************************************************************************/
void utls::clearSystem()
{
    system("CLS");
}

/* Purpose:  Get input from user
 *     Pre:  None
 *    Post:  User input returned as string
 ******************************************************************************/
std::string utls::getInput()
{
    std::string input = "";

    std::getline(std::cin, input);

    return input;
}

/* Purpose:  Check if string is longer than 0 characters
 *     Pre:  String
 *    Post:  Returns true if string is longer than 0 characters or false if not
 ******************************************************************************/
bool utls::hasLength(const std::string input)
{
    return !input.empty();
}

/* Purpose:  Check if string is alpha-numeric
 *     Pre:  String
 *    Post:  Returns true for alpha-numeric or false for not
 ******************************************************************************/
bool utls::isAlpha(const std::string input)
{
    bool alpha = false;

    if (!hasLength(input))
    {
        alpha = false;
    }
    else
    {
        for (unsigned int i = 0; i < input.length(); i++)
        {
            if (!isalpha(input[i]))
            {
                alpha = false;
                break;
            }
        }
    }
    return alpha;
}

/* Purpose:  Check if string is character
 *     Pre:  String
 *    Post:  Returns true for character or false for not
 ******************************************************************************/
bool utls::isChar(const std::string input)
{
    bool character = false;

    if (input.length() == 1)
    {
        if (isalpha(input[0]))
        {
            character = true;
        }
    }
    return character;
}

/* Purpose:  Check if string is decimal
 *     Pre:  String
 *    Post:  Returns true for decimal or false for not
 ******************************************************************************/
bool utls::isDecimal(const std::string input)
{
    bool decimal            = true;
    bool decimalPointPassed = false;

    if (!hasLength(input))
    {
        decimal = false;
    }
    else
    {
        for (unsigned int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                if (input[i] != '.')
                {
                    decimal = false;
                }
                else
                {
                    if (!decimalPointPassed)
                    {
                        decimalPointPassed = true;
                    }
                    else
                    {
                        decimal = false;
                        break;
                    }
                }
            }
        }
    }
    return decimal;
}

/* Purpose:  Check if string is digit
 *     Pre:  String
 *    Post:  Returns true for digit or false for not
 ******************************************************************************/
bool utls::isDigit(const std::string input)
{
    bool digit = true;

    if (!hasLength(input))
    {
        digit = false;
    }
    else
    {
        for (unsigned int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                digit = false;
                break;
            }
        }
    }
    return digit;
}

/* Purpose:  Check if input file exists
 *     Pre:  ifstream
 *    Post:  Returns true if input file exists
 ******************************************************************************/
bool utls::isFileExists(const std::ifstream & fin)
{
    bool valid = true;

    if (!fin)
    {
        valid = false;
    }
    return valid;
}

/* Purpose:  Check if output file exists
 *     Pre:  ofstream
 *    Post:  Returns true if output file exists
 ******************************************************************************/
bool utls::isFileExists(const std::ofstream & fout)
{
    bool valid = true;

    if (!fout)
    {
        valid = false;
    }
    return valid;
}

/* Purpose:  Check if input file is openable
 *     Pre:  ifstream
 *    Post:  Returns true if input file is openable
 ******************************************************************************/
bool utls::isFileReadable(const std::ifstream & fin)
{
    bool valid = true;

    if (fin.fail())
    {
        valid = false;
    }
    return valid;
}

/* Purpose:  Check if output file is openable
 *     Pre:  ofstream
 *    Post:  Returns true if output file is openable
 ******************************************************************************/
bool utls::isFileReadable(const std::ofstream & fout)
{
    bool valid = true;

    if (fout.fail())
    {
        valid = false;
    }
    return valid;
}

/* Purpose:  Check if input file exists and is openable
 *     Pre:  ifstream
 *    Post:  Returns true if input file exists and is openable
 ******************************************************************************/
bool utls::isValidFile(const std::ifstream &fin)
{
    bool valid = true;

    if (!utls::isFileExists(fin) || !utls::isFileReadable(fin))
    {
        valid = false;
    }
    return valid;
}


/* Purpose:  Check if output file is openable
 *     Pre:  ofstream
 *    Post:  Returns true if output file is openable
 ******************************************************************************/
bool utls::isValidFile(const std::ofstream &fout)
{
    bool valid = true;

    if (!utls::isFileExists(fout) || !utls::isFileReadable(fout))
    {
        valid = false;
    }
    return valid;
}

/* Purpose:  Check if string is letters, hyphens, and/or spaces
 *     Pre:  String
 *    Post:  Returns true if "words" or false if not
 ******************************************************************************/
bool utls::isWords(const std::string input)
{
    bool words = true;

    if (!hasLength(input))
    {
        words = false;
    }

    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (!isalpha(input[i]))
        {
            if (input[i] != '-' && input[i] != ' ')
            {
                words = false;
                break;
            }
        }
    }
    return words;
}

/* Purpose:  Pause the program
 *     Pre:  None
 *    Post:  Program is paused until input is received
 *  Source:  http://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
 ******************************************************************************/
void utls::pause()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* Purpose:  Pause the program via system call
 *     Pre:  None
 *    Post:  Program is paused until input is received
 *  Source:  http://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
 ******************************************************************************/
void utls::pauseSystem()
{
    system("PAUSE");
}

std::string utls::toLower(const std::string input)
{
    std::string output;

    for (unsigned int i = 0; i < input.length(); i++)
    {
        output += tolower(input[i]);
    }
    return output;
}

std::string utls::toUpper(const std::string input)
{
    std::string output;

    for (unsigned int i = 0; i < input.length(); i++)
    {
        output += toupper(input[i]);
    }
    return output;
}
