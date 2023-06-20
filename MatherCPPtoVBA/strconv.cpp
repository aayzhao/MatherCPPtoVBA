#include "pch.h"
#include "strconv.h"
#include <comdef.h>
#include <string>
#include <wtypes.h>
#include <oleauto.h>

//code provided by colleague

/*
void StringtoVBString(std::string CppString, BSTR* VBOutString) {

    try {
        SysFreeString(*VBOutString);

        // The next four lines work... but give a memory error.
        //char * tempChar = StringtoChar(&CppString);
        //BSTR tempBSTR = ChartoBSTR(tempChar);
        //*VBOutString = SysAllocString(tempBSTR);
        //delete tempChar; tempChar = 0;

        //This also works, and is simple!!!
        //*VBOutString = CppString.c_str();
        *VBOutString = SysAllocStringByteLen(CppString.c_str(), CppString.size());
    }
    catch (...) {
        //Stuff
        return;
    }
    return;
}
*/

//this code works in testing.
//found online at 
//https://stackoverflow.com/questions/6284524/bstr-to-stdstring-stdwstring-and-vice-versa 
//for converting wstrings and strings to BSTRs
BSTR ConvertMBSToBSTR(const std::string& str)
{
    int wslen = ::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
        str.data(), str.length(),
        NULL, 0);

    BSTR wsdata = ::SysAllocStringLen(NULL, wslen);
    ::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
        str.data(), str.length(),
        wsdata, wslen);
    return wsdata;
}

/*
*Code for going from BSTR to std::string
*/

//helper function
int BSTRLen(BSTR String)
{
    int Len = 0;
    int Pos = 0;
    bool Finish = false;
    if (String == NULL)
        return(0);
    while (!Finish)
    {
        unsigned int part = String[Pos];
        if (part == 0)
        {
            return(Len);
        }
        else
        {
            Len++;
        }
        Pos++;
    }
    return(0);
}

//main function
std::string BSTRtoString(BSTR inBSTR) {
    std::string ConvertedString = "";
    int Len = BSTRLen(inBSTR);

    if (Len > 0) {
        LPSTR buffer = (LPSTR)inBSTR;
        ConvertedString = (std::string)buffer;
    }
    return ConvertedString;
}

BSTR WINAPI test_function() // returns a VBA string of "test"
{
    return ConvertMBSToBSTR("test");
}

//function for testing the string conversions: will
//return "Yes" if given bstr is "Apple", "No" otherwise.
BSTR WINAPI is_apple(BSTR inBSTR)
{
    std::string str = BSTRtoString(inBSTR);
    if (str.compare("apple") == 0) {
        return ConvertMBSToBSTR("Yes");
    }
    return ConvertMBSToBSTR("No");
}
