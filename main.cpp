#include "StringSet.h"
#include <iostream>

using namespace std;

int main()
{
    StringSet *newStringArray = new StringSet();
    StringSet *newStringArray2 = new StringSet();
    newStringArray->insert("hello");
    newStringArray->insert("from");
    newStringArray->insert("the");
    newStringArray->insert("other");
    newStringArray->insert("side");
    newStringArray->find("the");
    newStringArray->remove("never");

    newStringArray2->insert("hello");
    newStringArray2->insert("it's");
    newStringArray2->insert("me");
    newStringArray2->insert("I've");
    newStringArray2->insert("been");
    newStringArray2->insert("wondering");

    newStringArray->unions(*newStringArray2);
    newStringArray->intersection(*newStringArray2);
    newStringArray->difference(*newStringArray2);


    return 0;
}
