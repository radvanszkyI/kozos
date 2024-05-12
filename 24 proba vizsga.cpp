#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct eloadas
{
	string nev;
	int honap, nap, sorszam, perc;
	string cim;
	string targyak;
};
eloadas tomb[1000] = {};
int n = 0; string sor;

eloadas split(string sorI, char elvalaszto) {
	eloadas ea;
	istringstream sorStream(sorI);

	string szo;

	getline(sorStream, szo, elvalaszto);
	ea.nev = szo;
	getline(sorStream, szo, elvalaszto);
	ea.honap = stoi(szo);
	getline(sorStream, szo, elvalaszto);
	ea.nap = stoi(szo);
	getline(sorStream, szo, elvalaszto);
	ea.sorszam = stoi(szo);
	getline(sorStream, szo, elvalaszto);
	ea.perc = stoi(szo);
	getline(sorStream, szo, elvalaszto);
	ea.cim = szo;
	getline(sorStream, szo, elvalaszto);
	ea.targyak = szo;
	return ea;
}
void feladat_1()
{
	ifstream be("eloadasok.txt");
	while (getline(be, sor)) //beszippantja az egész sort 1 db string-be
	{
		tomb[n] = split(sor, '\t');
		n++;
	}
	//	n = n - 1;

	be.close();

	/*for(int i=0;i<n;i++)
	{
		cout<<tomb[i].nev<<'\t'<<
		tomb[i].honap<<'\t'<<
		tomb[i].nap<<'\t'<<
		tomb[i].sorszam<<'\t'<<tomb[i].perc<<'\t'<<
		tomb[i].cim<<'\t'<<
		tomb[i].targyak<<endl;
	}*/
}
void feladat_2()
{
	cout << "november 5.:" << endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tomb[j].nap == 5 && tomb[j].sorszam == i + 1)
			{
				cout << "  " << i + 1 << "." << tomb[j].nev << ": " << tomb[j].cim << endl;
			}
		}
	}
	cout << "november 6.:" << endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tomb[j].nap == 6 && tomb[j].sorszam == i + 1)
			{
				cout << "  " << i + 1 << "." << tomb[j].nev << ": " << tomb[j].cim << endl;
			}
		}
	}cout << "november 7.:" << endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tomb[j].nap == 7 && tomb[j].sorszam == i + 1)
			{
				cout << "  " << i + 1 << "." << tomb[j].nev << ": " << tomb[j].cim << endl;
			}
		}
	}cout << "november 8.:" << endl;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tomb[j].nap == 8 && tomb[j].sorszam == i + 1)
			{
				cout << "  " << i + 1 << "." << tomb[j].nev << ": " << tomb[j].cim << endl;
			}
		}
	}
}
void feladat_3()
{
	int szamlalo = 0;
	int eloadasido = 0;

	for (int i = 0; i < n; i++)
	{
		if (tomb[i].nap == 5)
		{
			eloadasido = eloadasido + tomb[i].perc;
		}
	}
	cout << endl << "1. nap: " << eloadasido / 60 << ":" << eloadasido % 60 << endl;

	eloadasido = 0;
	for (int i = 0; i < n; i++)
	{
		if (tomb[i].nap == 6)
		{
			eloadasido = eloadasido + tomb[i].perc;
			szamlalo++;
		}
	}
	cout << "2. nap: " << eloadasido / 60 << ":" << eloadasido % 60 << endl;

	eloadasido = 0;
	for (int i = 0; i < n; i++)
	{
		if (tomb[i].nap == 7)
		{
			eloadasido = eloadasido + tomb[i].perc;
		}
	}
	cout << "3. nap: " << eloadasido / 60 << ":" << eloadasido % 60 << endl;


	eloadasido = 0;
	for (int i = 0; i < n; i++)
	{
		if (tomb[i].nap == 8)
		{
			eloadasido = eloadasido + tomb[i].perc;
		}
	}
	cout << "4. nap: " << eloadasido / 60 << ":" << eloadasido % 60 << endl;
}
void feladat_4()
{
	int eloadashossz = 0;

	for (int i = 0; i < n; i++)
	{
		if (tomb[i].perc > eloadashossz)
		{
			eloadashossz = tomb[i].perc;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (tomb[i].perc == eloadashossz)
		{
			cout << endl << "eloado neve: " << tomb[i].nev << "  eloadas hossza: " << tomb[i].perc << endl;
		}
	}
}
void feladat_5()
{
	int m = 5;
	while (m < 9)
	{
		int eloadassz = 0;
		int ido = 8 * 60;

		for (int i = 0; i < n; i++)
		{
			if (tomb[i].nap == m)
			{
				ido = tomb[i].perc + ido;
				eloadassz++;
			}
		}
		ido = ido + (eloadassz * 20);
		if (ido / 60 > 12)
		{
			ido = ido + 60;
		}
		cout << endl << "november " << m << ".: " << ido / 60 << ":" << ido % 60;
		m++;
	}
}
void feladat_6()
{
	bool vege = false;
	int ido = 8 * 60;

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (tomb[j].nap == 7 && tomb[j].sorszam == i + 1)
			{
				ido = tomb[j].perc + ido + 20;
			}
			if (ido / 60 >= 12)
			{
				vege = true;
				break;
			}
		}
		if (vege == true)
		{
			break;
		}

	}
	cout << endl << "A harmadik napon " << ido / 60 << ":" << ido % 60 << "-kor kezdodik az ebed szunet";
}
void feladat_7()
{
	bool talalt = false;
	int szamlalo = 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (tomb[i].nev == tomb[i + 1].nev)
		{
			szamlalo++;
			talalt = true;
		}
		else
			if (szamlalo > 1)
			{
				cout << tomb[i].nev << " " << szamlalo << endl;
				szamlalo = 1;
			}
		if (szamlalo > 1 && i + 1 == n - 2)
		{
			cout << tomb[i].nev << " " << szamlalo << endl;
		}
	}

	if (talalt == false)
	{
		cout << "Nem taléalt egyezo neveket";
	}
}
int mikor_er_veget(int mnap)
{
	int eloadassz = 0;
	int ido = 8 * 60;

	for (int i = 0; i < n; i++)
	{
		if (tomb[i].nap == mnap)
		{
			ido = tomb[i].perc + ido;
			eloadassz++;
		}
	}
	ido = ido + (eloadassz * 20);
	if (ido / 60 > 12)
	{
		ido = ido + 60;
	}
	return ido;
}
void feladat_8()
{
	int cnap, ora, cperc, ido; bool igaze = false, ebedszunete = false;
	cout << endl << "irjon egy napot: ";
	cin >> cnap;
	cout << "irjon egy orat: ";
	cin >> ora;
	cout << "irjon percet: ";
	cin >> cperc;

	cperc = ora * 60 + cperc;
	if (ora < 8)
	{
		cout << "Meg nem kezdodott el.";
	}
	else
		if (mikor_er_veget(cnap) < cperc)
		{
			cout << "Mar veget ert.";
		}
		else
		{

			int i = 0;
			ido = 8 * 60;
			while (i < n && igaze == false)
			{
				for (int j = 0; j < n; j++)
				{
					if (tomb[j].sorszam == i + 1 && tomb[j].nap == cnap)
					{						
						ido = tomb[j].perc + ido;
						
						if (ido > cperc)//tulment az ELŐADÁS a megadott időn
						{
							cout << "Eloadas";
							igaze = true;
							break;
						}
						else ido = 20 + ido;
						if (ido > cperc)//tulment az VITA a megadott időn
						{
							cout << "Vita";
							igaze = true;
							break;
						}
						if (ido / 60 >= 12 && ebedszunete == false)
						{
							ido = ido + 60;
							ebedszunete == true;
							if (ido > cperc)//tulment az EBÉDSZÜNET a megadott időn
							{
								cout << "Ebedszunet";
								igaze = true;
								break;
							}
						}
						
					}

				}
				i++;
			}
		}

}
int main()
{
	feladat_1();
	cout << "2.feladat "; feladat_2();
	cout << endl << "3.feladat "; feladat_3();
	cout << endl << "4.feladat "; feladat_4();
	cout << endl << "5.feladat "; feladat_5();
	cout << endl << "6.feladat "; feladat_6();
	cout << endl << "7.feladat "; feladat_7();
	cout << endl << "8.feladat "; feladat_8();

}
