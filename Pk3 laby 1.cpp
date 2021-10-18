// pk3my_21_lab01.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;

struct osoba {
	string nazwisko, stanowisko;
	osoba(string a, string b) { nazwisko = a; stanowisko = b; };
	osoba() { nazwisko = ""; stanowisko = ""; }
};
ostream& operator<<(ostream& os, const osoba& cz)
{
	os << cz.nazwisko << " " << cz.stanowisko << endl;
	return os;
}
//Zadanie 1 (0.7 pkt.)
//Stwórz szablon dla funkcji maks dwuargumentowej(załóż, że oba typy argumentów są takie same), który zwraca większą wartość.Przetestuj na
//przykładach.
//Czy funkcja działa na typach const char* ? Dlaczego ?
// nie działa ponieważ porównuje wskaźniki na pamięć
// ponieważ porównuje adresy a nie wartości zmiennych
template <typename T>
T maks(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}
//Zadanie 2 (0.6 pkt.)
//Stwórz szablon szczegółowy, który dla funkcji z zad 1, będzie działał poprawnie dla typu const char* (zwraca większą wartość).
//Podpowiedź: dla typów string można łatwo porównywać wartości
template <> const char* maks(const char* a, const char* b) {
	string x, y;
	x = a;
	y = b;
	if (x > y)
		return a;
	return b;
}
//Zadanie 3 (1 pkt.)
//Stwórz szablon dla klasy CPojemnik.Niech klasa zawiera
//* prywatną dynamiczną tablicę zadanego typu
//* składową prywatną int n mówiącą ile elementów jest już wstawionych do tablicy
//* składową prywatną int poj mówiącą o wielkości tablicy(jej pojemności)
//a) Stwórz konstruktor domyślny, gdzie poj = 0, konstruktor 1 - argumentowy(zależny od parametru poj), pamiętaj o destruktorze.
//b) Dodaj metodę void wstaw, gdzie argumentami będzie miejsce w pojemniku(tablicy) oraz wstawiany obiekt(funkcja z 2 arg).Pamiętaj o
//sprawdzeniu zakresu tablicy, jeśli będziemy poza zakresem, nic nie dodajemy, tylko zwracamy komunikat o przekroczonym zakresie.
//c) Dodaj metodę void dodaj, gdzie argumentem będzie wstawiany obiekt(funkcja z 1 arg).Pamiętaj o sprawdzeniu pojemności tablicy, ile
//elementów już się tam znajduje.Jeśli przekroczymy pojemność, zwiększaj ją o 3.
//d) Dodaj metodę wyświetl, która będzie wyświetlała elementy z pojemnika.
//Zadeklaruj obiekt mojpoj typu CPojemnik, który pomieści 3 obiekty typu osoba oraz obiekt mojpoj2 typu CPojemnik, który pomieści 3 obiekty
//typu double.
template <class T1>
class CPojemnik
{
private:
	vector<T1> lista;
	int n;
	int poj;
public:

	void wstaw(T1 rodzaj, int miejsce)
	{
		if (miejsce > poj || miejsce < 0)
		{
			cout << "Brak pojemności w pojemniku" << endl;
			return;
		}
		lista[miejsce] = rodzaj;
	}
	void dodaj(T1 rodzaj)
	{
		if (poj == 0)
		{
			poj = 3;
			lista.reserve(3);
		}
		if (n == lista.capacity())
		{
			int x = lista.capacity() + 3;
			lista.reserve(x);
			poj = lista.capacity();
		}
		lista.push_back(rodzaj);
		n++;
	}
	void wyświetl()
	{
		for (auto& x : lista)
			cout << x << endl;
		//cout << lista.capacity() << endl;
	}
	CPojemnik()
	{
		poj = 0;
		n = 0;
	}
	CPojemnik(int p_poj)
	{
		poj = p_poj;
		n = 0;
		lista.reserve(poj);
	}
	~CPojemnik() {};
};
//Zadanie 4 (1 pkt.)
//Stwórz klasę CPojemnikD, która dziedziczy po klasie CPojemnik dla szczegółowego typu jakim jest double.Niech klasa zawiera dodatkowo
//pole double suma.Na początku suma wynosi 0;
//W klasie przedefiniuj funkcję void dodaj, tak, aby uruchamiała się ta funkcja z klasy głównej oraz dodatkowo dodawała wartość dodawanego
//obiekt do wartości suma(czyli ostatecznie suma określa sumę wszystkich obiektów w pojemniku).
//Dodaj do klasy metodę zwrocsuma() zwracającą wartość ‘suma’.
//Zadeklaruj obiekt pojD typu CPojemnikD, który pomieści 3 obiekty.
//template <class T1>
class CPojemnikD : public CPojemnik<double>
{
private:
	double suma;
public:
	void dodaj(double liczba)
	{
		suma += liczba;
		CPojemnik::dodaj(liczba);
	}
	double zwrocsuma()
	{
		return suma;
	}
	CPojemnikD() : CPojemnik()
	{
		suma = 0;
	}
	CPojemnikD(int x) :CPojemnik(x)
	{
		suma = 0;
	}
	~CPojemnikD()
	{
	}
};
//Zadanie 5 (0.7 pkt.)
//a) Stwórz szablon klasy CPojemnikDopis, która dziedziczy po klasie CPojemnikD, który zawiera dodatkowe pole opis zadanego typu.
//b) Zadeklaruj obiekt pojDopis typu CPojemnikDopis, który pomieści 3 obiekty, opis jest typu string(np. "jestem lista")
//c) Zadeklaruj obiekt pojDopis2 typu CPojemnikDopis, który pomieści 3 obiekty, opis jest typu osoba(np.o1)
template <class T2>
class CPojemnikDopis : public CPojemnikD
{
private:
	T2 opis;
public:

	CPojemnikDopis() : CPojemnikD()
	{
	}
	CPojemnikDopis(int p_poj) : CPojemnikD(p_poj)
	{
	}
	~CPojemnikDopis()
	{
	}
};
int main()
{
	/* Odkomentuwujemy tylko kod z //    */
	cout << "\n\t======== ZAD 1 i 2 ==== \n";
	cout << maks(1, 2) << ": odp 2" << endl;
	cout << maks(20.2, 2.3) << ": odp 20.2" << endl;
	cout << maks(-2.2, 2.2) << ": odp 2.2" << endl;
	cout << maks('c', 'a') << ": odp c" << endl << endl;
	cout << maks("aaaa", "bz") << ": odp bz" << endl;
	cout << maks("aa", "az") << ": odp az" << endl;
	cout << maks("aaaa", "bz") << ": odp bz" << endl;
	cout << maks("aaaaaaa", "a") << ": odp aaaaaa" << endl;
	cout << maks("aaz", "zzd") << ": odp zzd" << endl;

	cout << "\n\n\t======== ZAD 3 ======== \n";
	osoba o1("Kowalski", "kucharz"), o2("Nowak", "kelner"), o3("Adamski", "barman");

	/*Zadeklaruj obiekt mojpoj typu CPojemnik, który pomieści 3 obiekty typu osoba */
	CPojemnik<osoba> mojpoj(3);    /* deklaracja mojpoj */
	mojpoj.dodaj(o1);
	mojpoj.dodaj(o2);
	mojpoj.dodaj(o3);
	mojpoj.dodaj(o2);
	mojpoj.wstaw(o1, -1);
	mojpoj.wstaw(o1, 0);

	/*Zadeklaruj obiekt mojpoj2 typu CPojemnik, który pomieści 3 obiekty typu double */
	CPojemnik<double> mojpoj2(3);  /* deklaracja mojpoj2 */
	mojpoj2.dodaj(0.0);
	mojpoj2.dodaj(1.1);
	mojpoj2.dodaj(200);
	mojpoj2.dodaj(3.3);
	mojpoj2.dodaj(4.4);
	mojpoj2.dodaj(5.5);
	cout << "\nmojpoj2\n";
	mojpoj2.wyświetl();
	mojpoj2.wstaw(2.2, 2);
	cout << "mojpoj2\n";
	mojpoj2.wyświetl();

	cout << "\n\t======== ZAD 4 ======== \n";
	cout << "\nDane dla klasy: CPojemnikD\n";
	/* Zadeklaruj obiekt pojD typu CPojemnikD, który pomieści 3 obiekty. */
	CPojemnikD/*<double>*/ pojD(3);    /* deklaracja pojD */
	pojD.dodaj(0);
	pojD.dodaj(10000.1);
	pojD.dodaj(2000.1);
	pojD.dodaj(300.1);
	pojD.dodaj(40.1);
	pojD.dodaj(5.1);
	pojD.wyświetl();
	cout << "Suma: " << pojD.zwrocsuma() << ": odp 12345.5" << endl;

	cout << "\n\t======== ZAD 5 ======== \n";
	/*b) Zadeklaruj obiekt pojDopis typu CPojemnikDopis, który pomieści 3 obiekty, opis jest typu string (np. "jestem lista" )*/
	CPojemnikDopis<string> pojDopis(3);    /* deklaracja pojDopis */
	pojDopis.dodaj(123.123);
	cout << "pojDopis" << endl;
	pojDopis.wyświetl();

	/*c) Zadeklaruj obiekt pojDopis2 typu CPojemnikDopis, który pomieści 3 obiekty, opis jest typu osoba  (np. o1)*/
	CPojemnikDopis<osoba> pojDopis2(3); /* deklaracja pojDopis2 */
	pojDopis2.dodaj(-222);
	cout << "\npojDopis2" << endl;
	pojDopis2.wyświetl();

	cout << "\n\t==== Koniec programu ==== \n";
}