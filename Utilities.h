/*
 * Author:          Matthew James Harrison
 * Class:           CSI-240-04
 * Date Updated:    04-Mar-16
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
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <fstream>
#include <iostream>
#include <string>

namespace utls
{
    void        clear         ();
    std::string getInput      ();
    bool        hasLength     (const std::string   input);
    bool        isAlpha       (const std::string   input);
    bool        isChar        (const std::string   input);
    bool        isDecimal     (const std::string   input);
    bool        isDigit       (const std::string   input);
    bool        isFileExists  (const std::ifstream &fin);
    bool        isFileExists  (const std::ofstream &fout);
    bool        isFileReadable(const std::ifstream &fin);
    bool        isFileReadable(const std::ofstream &fout);
    bool        isValidFile   (const std::ifstream &fin);
    bool        isValidFile   (const std::ofstream &fout);
    bool        isWords       (const std::string   input);
    void        pause         ();
    std::string toLower       (const std::string input);
    std::string toUpper       (const std::string input);
}

#endif