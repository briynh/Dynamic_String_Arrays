#ifndef STRINGSET_H
#define STRINGSET_H

#include <string>

class StringSet
{
    public:
        StringSet();
        virtual ~StringSet();
        StringSet(const StringSet & toBeCopied);
        bool insert(std::string toBeInserted);
        bool remove(std::string toBeRemoved);
        int find(std::string toBeFound) const;
        int size() const;
        StringSet unions(const StringSet & toBeUnioned) const;
        StringSet intersection(const StringSet & toBeIntersectioned) const;
        StringSet difference(const StringSet & toBeDifferenced) const;
        void printAll();
    protected:

    private:
        std::string *Array = new std::string[4];
        int maxSize, currentSize;
};

#endif // STRINGSET_H
