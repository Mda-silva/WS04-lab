/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Fridge.h"
using namespace std;

namespace seneca {

    const char* Food::name() const {

        return m_name;

    }

    int Food::weight() const {
        return m_weight;

    }
    Food::Food() {}

    Food::Food(const char* nm, int wei) {
        strncpy(m_name, nm, NAME_LEN);
        m_weight = wei;
    }

    Fridge::Fridge()
    {
        m_numFoods = 0;
        m_model = nullptr;
    }

    Fridge::Fridge(Food farr[], int nf, const char* mod)
    {
        if (nf > 0) 
        {
            m_numFoods = 0;
            m_model = nullptr;
            m_numFoods = nf;
            m_model = new char[strlen(mod) + 1];

            if (mod == nullptr || mod[0] == '\0')
            {

                strcpy(m_model, "Ice Age");

            }
            else if (mod != nullptr && mod[0] != '\0')
            {

                strcpy(m_model, mod);

            }
           
            for (int i = 0; i < nf && nf <= FRIDGE_CAP; i++)
            {

                m_foods[i] = farr[i];

            }
        }
    }

    Fridge::~Fridge()
    {

        if (m_model != nullptr)
        {

            delete[] m_model;

            m_model = nullptr;

        }
    }
    
    
    bool Fridge::addFood(const Food& f)
    {
        bool added = false;

        if (m_numFoods < FRIDGE_CAP)
        {

            m_foods[m_numFoods] = f;

            m_numFoods++;

            added = true;

        }

        return added;
    }

    void Fridge::changeModel(const char* m)
    {

        if (m[0] != '\0' && m != nullptr)
        {

            delete[] m_model;

            m_model = new char[NAME_LEN];

            strcpy(m_model, m);

        }
    }

    bool Fridge::fullFridge() const
    {
        bool full = false;

        if (m_numFoods == FRIDGE_CAP)
        {

            full = true;

        }


        return full;
    }

    bool Fridge::findFood(const char* f) const
    {
        bool found = false;

        for (int i = 0; i < m_numFoods && !found; i++)
        {

            if (strcmp(f, m_foods[i].name()) == 0)

            {

                found = true;

            }
        }

        return found;
    }

    std::ostream& Fridge::display(std::ostream& os) const
    {      
    

        if (m_model != nullptr && m_model[0] != '\0')
        {

            os << "Fridge Model: " << m_model << endl;
            os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << endl;
            os << "List of Foods\n";

            if (m_numFoods > 0)
            {
                for (int i = 0; i < m_numFoods; i++)
                {
                    os.width(NAME_LEN);
                    os.setf(ios::right);
                    os << m_foods[i].name();
                    os << " | " << m_foods[i].weight() << endl;
                }              
            }
        }

        return os;
    }
}