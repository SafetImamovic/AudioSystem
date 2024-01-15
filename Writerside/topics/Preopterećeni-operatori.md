# Preopterećeni operatori

# Primjer korištenja operatora: 


Operator sabiranja klasa:

```c++
void SkupPjesama::operator+(const Pjesma& pjesma)
{
this->BrojPjesama++;
this->Pjesme.push_back(pjesma);
}
```

Operator oduzimanja klasa:
```c++
void SkupPjesama::operator-(const Pjesma& pjesma)
{
    this->BrojPjesama--;
    for (int i = 0; i < this->Pjesme.size(); i++)
    {
        if (pjesma.getID_Pjesme() == this->Pjesme.at(i).getID_Pjesme())
        {
            this->Pjesme.erase(this->Pjesme.begin() + i - 1);
            break;
        }
    }
}
```



