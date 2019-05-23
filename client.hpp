#pragma once

#include "data.hpp"

class client {
    dataAbs* pData;
    bool added;
public:
    client() {
        dType type = nat;
        pData = dataAbs::Create(type);
        added = false;
    }
    ~client() {
        if (!added && pData) {
            delete pData;
            pData = NULL;
        }
    }

    dataAbs* getData() {
        return pData;
    }

    void addedInLibrary() { added = true; }
};