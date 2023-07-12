#include <iostream>
#include <ctime>
using namespace std;

class Bank 
{
public: 
    struct BankLvl
{
    int lvl;
    int ecm;
    int ECMprice;
    int egp;
    int EGPprice;
    int NextLvl[5];
};
      int lvlcount = 0;
      int BankLvlNow;
      BankLvl Levels[5];
      Bank()
      {
          BankLvlNow = 0;
          Levels[0].lvl = 1;
          Levels[0].ecm = 1;
          Levels[0].ECMprice = 800;
          Levels[0].egp = 3;
          Levels[0].EGPprice = 6500;
          Levels[0].NextLvl[0] = 4;
          Levels[0].NextLvl[1] = 4;
          Levels[0].NextLvl[2] = 2;
          Levels[0].NextLvl[3] = 1;
          Levels[0].NextLvl[4] = 1;

          Levels[1].lvl = 2;
          Levels[1].ecm = 2;
          Levels[1].ECMprice = 650;
          Levels[1].egp = 3;
          Levels[1].EGPprice = 6000;
          Levels[1].NextLvl[0] = 3;
          Levels[1].NextLvl[1] = 4;
          Levels[1].NextLvl[2] = 3;
          Levels[1].NextLvl[3] = 1;
          Levels[1].NextLvl[4] = 1;

          Levels[2].lvl = 3;
          Levels[2].ecm = 2;
          Levels[2].ECMprice = 500;
          Levels[2].egp = 2;
          Levels[2].EGPprice = 5500;
          Levels[2].NextLvl[0] = 3;
          Levels[2].NextLvl[1] = 4;
          Levels[2].NextLvl[2] = 3;
          Levels[2].NextLvl[3] = 1;
          Levels[2].NextLvl[4] = 1;

          Levels[3].lvl = 4;
          Levels[3].ecm = 3;
          Levels[3].ECMprice = 400;
          Levels[3].egp = 2;
          Levels[3].EGPprice = 5000;
          Levels[3].NextLvl[0] = 3;
          Levels[3].NextLvl[1] = 4;
          Levels[3].NextLvl[2] = 3;
          Levels[3].NextLvl[3] = 1;
          Levels[3].NextLvl[4] = 1;

          Levels[4].lvl = 5;
          Levels[4].ecm = 3;
          Levels[4].ECMprice = 300;
          Levels[4].egp = 1;
          Levels[4].EGPprice = 4500;
          Levels[4].NextLvl[0] = 3;
          Levels[4].NextLvl[1] = 4;
          Levels[4].NextLvl[2] = 3;
          Levels[4].NextLvl[3] = 1;
          Levels[4].NextLvl[4] = 1;
      }

      void NextLvlBank(int i)
      {
          BankLvlNow = i;
      }

      void Banklvlcount(int x)
      {
          lvlcount++;
      }

      void Random()
      {
          int NextStep = 0;
          int random = rand() % 12 + 1; // 10 
          for (int j = 0; j < 5; j++)
          {
              if (random > 0 || random == 0)
              {
                  NextStep = j;
              }
              random = random - Levels[BankLvlNow].NextLvl[j]; // i = BankLvl (struct) // j = for и NextLvl структуры
              // 10 - 3 = 7 // 7 - 4 = 3 // 3 - 3 = 0
          }
          NextLvlBank(NextStep);
          Banklvlcount(lvlcount);
      }

      void Print()
      {
          cout << "Lvl = " << Levels[BankLvlNow].lvl << endl;
      }
};

class Company
{
public:
    string name;
    int factory;
    int autofactory;
    int ECM;
    int EGP;
    int credit;
    int capital=capital + credit;
    int count = 0;

    Company(string name,int factory,int autofactory,int ECM,int EGP,int credit,int capital)
    {
       this-> name = name;
       this-> factory = factory;
       this-> autofactory = autofactory;
       this-> ECM = ECM;
       this-> EGP = EGP;
       this-> credit = credit;
       this-> capital = capital + credit;
    }
    
    void manufacture() 
    {
        int x = 0;
        cout << "В вашем распоряжении " << ECM << " единиц сырья, "<< factory <<" обычных фабрик "<< autofactory << " автоматизированных фабрик" << endl;
        cout << "Затраты для переработки 1 единицы сырья на обычной фабрике 2000$" << endl;
        cout << "Затраты для переработки 1 единицы сырья на автоматизированнй фабрике 2000$ или 3000$ за 2 единицы" << endl;
        cout << "Сколько единиц сырья вы хотите переработать в этом месяце?" << endl;
        cin >> x;
        if (x > ECM)
        {
            cout << "У вас нет такого количества сырья" << endl;
        }
        if (capital < (x * 2000))
        {
            cout << "У вас недостаточно денег для начала производства" << endl;
        }
        else if (autofactory < 1 && factory > 0)
        {
            capital -= (x * 2000);
            ECM -= x;
            EGP += x;
        }


    };
    void buy(Bank&bank,int BankLvlNow)
    {
        int n = 0;
        int p = 0;
        cout << "Доступно для покупки: " << bank.Levels[BankLvlNow].ecm << " единиц сырья стоимостью от: " << bank.Levels[BankLvlNow].ECMprice << endl;
        cout << "Введите желаемое количество сырья для покупки: " << endl;
        cin >> n;
        if (n > bank.Levels[BankLvlNow].ecm)
        {
            cout << "Вы превысили возможное количество сырья для покупки" << endl;
        }
        cout << "Введите цену для покупки 1 единицы сырья: " << endl;
        cin >> p;
        if (p < bank.Levels[BankLvlNow].ECMprice)
        {
            cout << "Вы указали цену ниже рыночной" << endl;
        }
        else
        {
            capital -= (n * p);
            ECM += n;
            bank.Levels[BankLvlNow].ecm -= n;
        }
    }
    void sell(Bank& bank, int BankLvlNow)
    {
        int n = 0;
        int p = 0;
        cout << "Доступно для продажи: " << bank.Levels[BankLvlNow].egp << " единиц товаров стоимость до: " << bank.Levels[BankLvlNow].EGPprice << endl;
        cout << "Введите желаемое количество товаров для продажи: " << endl;
        cin >> n;
        if (n > bank.Levels[BankLvlNow].egp)
        {
            cout << "Вы превысили максимальное количество товаров для продажи" << endl;
        }
        cout << "Введите цену товаров для продажи: " << endl;
        cin >> p;
        if (p > bank.Levels[BankLvlNow].EGPprice)
        {
            cout << "Вы превысили максимальную стоимость товаров для продажи" << endl;
        }
        else
        {
            EGP -= n;
            capital += (n * p);
            bank.Levels[BankLvlNow].egp -= n;
        }
    };
    void build()
    {
        int choice = 0;
        cout << "Вам дуступна постройка фабрики, стоимость постройки 5000$" << endl;
        cout << "Введите 1 - для начала строитеьства, 2 - для отмены." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if ((factory + autofactory) >= 6)
            {
                cout << "У вас максимальное количество фабрик" << endl;
            }
            if (capital < 5000)
            {
                cout << "У вас недостаточно денег для постройки " << endl;
            }
            else
            {
                capital -= 5000;
                factory += 1;
            }
            break;
        case 2:
            break;
        }
    };
    void upgrade()
    {
        int choice = 0;
        cout << "Вам доступно улучшение фабрик до автоматизированных" << endl;
        cout << "У вас в собственности " << factory << " обычных фабрик" << endl;
        cout << "Затраты на улучшение 1 фабрики 7000$ " << endl;
        cout << "Введите 1 - для улучшения фабрики,  2 - для отмены" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                if (autofactory >= 6)
                {
                    cout << "Все ваши фабрики уже автоматизированы" << endl;
                }
                if (factory == 0)
                {
                    cout << "У вас нет фабрик для автоматизации" << endl;
                }
                if (capital < 7000)
                {
                    cout << "У вас недостаточно денег" << endl;
                }
                else
                {
                    capital -= 7000;
                    factory -= 1;
                    autofactory += 1;
                }
                break;
            case 2:
                break;
        }
    };
    void buildAuto()
    {
        int choice = 0;
        cout << "Вам дуступна постройка автоматизированной фабрики, стоимость постройки 10000$" << endl;
        cout << "Введите 1 - для начала строитеьства, 2 - для отмены." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if ((factory + autofactory) >= 6)
            {
                cout << "У вас максимальное количество фабрик" << endl;
            }
            if (capital < 10000)
            {
                cout << "У вас недостаточно денег для постройки " << endl;
            }
            else
            {
                capital -= 10000;
                autofactory += 1;
            }
            break;
        case 2:
            break;
        }
    };
    void getCredit()
    {
        int choice;
        int cred = (capital / 2);
        cout << "Вам доступна ссуда от банка в размере " << cred << " $ сроком на 12 месяцев" << endl;
        cout << "Введите 1 - получить ссуду, 2 - отказаться" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            credit += cred;
            capital += cred;
        }
        break;
        case 2:
            break;
        }
    };
    void Count(int count)
    {
        count++;
    }
    void MonPay() 
    {
        capital -= ((factory * 1000) + (autofactory * 1500) + (ECM * 300) + (EGP * 500));
        if (credit > 0)
        {
            capital -= (credit / 100);
            Count(count);
        }
        if (count == 12)
        {
            capital -= credit;
            credit = 0;
            count = 0;
        }
    }
    void printCompany()
    {
        cout << "Данные компании: " << endl;
        cout << "Наименование: " << name << endl;
        cout << "Количество фабрик: " << factory << endl;
        cout << "Количество автоматизированных фабрик: " << autofactory << endl;
        cout << "Единиц сырья: " << ECM << endl;
        cout << "Единиц товаров: " << EGP << endl;
        cout << "Сумма ссуды: " << credit << endl;
        cout << "Текущий капиталл: " << capital << endl;
    }

};



int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
   
    Company company{"F",2,0,4,2,0,10000};
    Bank bank{};
    bank.NextLvlBank(2);

    int choice;
    int i=0;
   
    cout << "Добро пожаловать в игру  # Менеджер # !!!" << endl;
    do
    {
        cout << "Выберите действие: " << endl;
        cout << "1 - статус компании" << endl << "2 - уровень спроса/предложения в текущем месяце" << endl
            << "3 - заявка на покупку сырья" << endl << "4 - заявка на производство товаров" << endl
            << "5 - заявка на продажу товаров" << endl << "6 - построить простую фабрику" << endl
            << "7 - улучшить фабрику" << endl << "8 - построить автоматизированную фабрику" << endl
            << "9 - получить ссуду" << endl << "0 - перейти к следущему месяцу управления" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: company.printCompany(); break;
        case 2: bank.Print(); break;
        case 3: company.buy(bank,bank.BankLvlNow); break;
        case 4: company.manufacture(); break;
        case 5: company.sell(bank, bank.BankLvlNow); break;
        case 6: company.build(); break;
        case 7: company.upgrade(); break;
        case 8: company.buildAuto(); break;
        case 9: company.getCredit(); break;
        case 0: bank.Random(),company.MonPay(); i++; cout << bank.lvlcount; break;
        }
    } while ( (i < 25 && company.capital >= 0) );
    cout << "Конец игры " << endl;
    return 0;
}