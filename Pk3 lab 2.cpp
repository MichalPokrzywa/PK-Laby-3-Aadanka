// pk3my_21_lab02.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include <vector>       // std::vector
#include <array>        // std::array
#include <list>         // std::list
#include <deque>        // std::list
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <ctime>


using namespace std;

template<typename T>
static void drukuj(T POJ, bool x = 0)
{
	char podz = ',';
	if (x)
		podz = '\n';

	int size = POJ.size();
	if (size <= 0) {
		std::cout << "Kontener nie istnieje";
		return;
	}
	std::cout << '{';
	for (int l = 0; l < size - 1; l++) {
		std::cout << POJ[l];
		std::cout << podz;
	}
	std::cout << POJ[size - 1];
	std::cout << "}";
}



class MojeTrio
{
	int a;
	double b;
	float c;
public:
	MojeTrio() :a(0), b(0), c() {};
	MojeTrio(int _a) :a(_a)
	{
		b = (rand() % 100000) / 1000.0;
		c = (rand() % 10000) / 1000.0;
	}
	double get_tosort(int x) 
	{ 
		if(x==1)
			return a;
		if(x==2)
			return b;
		if(x==3)
			return (a + b + c);
		 
	}; //  funkcja zwraca wartosc stosowana przy sortowaniu, moze to byc a b c lub cos inneo np. suma 3 liczb
	friend ostream& operator<<(ostream& os, const MojeTrio& dt);
};
ostream& operator<<(ostream& s, const MojeTrio& dt)
{
	s << dt.a << '\t' << dt.b << '\t' << dt.c;
	return s;
}
bool sorting(MojeTrio a,MojeTrio b)
{
	return a.get_tosort(1) < b.get_tosort(1);

}
class sorting2
{
public:
	bool operator() (MojeTrio a, MojeTrio b)
	{
		return a.get_tosort(1) < b.get_tosort(1);
	}
};
class Chose_sorting
{

public:
	enum Option {
		By_int,
		By_double,
		By_float
	};
	Chose_sorting(Option option) : option(option) {}
	auto operator() (MojeTrio a, MojeTrio b)
	{
		switch (option)
		{
		case By_int:
			return by_int(a) < by_int(b);
		case By_double:
			return by_double(a) < by_double(b);
		case By_float:
			return by_float(a) < by_float(b);
		default:
			break;
		}
	}

	int by_int(MojeTrio a)
	{
		int x = a.get_tosort(1);
		return x;
	}
	double by_double(MojeTrio a)
	{
		double y = a.get_tosort(2);
		return y;
	}
	float by_float(MojeTrio a)
	{
		float z = a.get_tosort(3);
		return z;

	}
private:
	Option option;
};






int main()
{

	srand(time(NULL));

	cout << "Michal Pokrzywa " << endl;
	vector<int> Vec1 = { 10, 10, 3, 4, 10, 10, 7, 10, 10 };
	int licznik = -1;

	cout << "\n\nZAD 1: ZLICZANIE\n";

	// a)	Ile 10 jest w całym wektorze
	licznik = count(Vec1.begin(), Vec1.end(), 10); //ile jest w całym wektorze
	
	cout << "W calym wektorze '10' jest: " << licznik << (" (pop: 6)\n");

	// b)	Ile 10 jest na końcu wektora. Ponieważ pozycja końca jest jedna, może być 1 lub 0 (jest albo nie 10).
	licznik = count(Vec1.end()-1, Vec1.end(), 10);
	cout << "Na koncu '10' jest: " << licznik << (" (pop: 1)\n");

	//c)	Ile 10 jest od drugiego do przedostatniego elementu wektora.
	licznik = count(Vec1.begin()+1, Vec1.end()-1, 10);
	cout << "Od drugiego do przedostatniego elementu w wektorze 10 jest: " << licznik << (" (pop: 4)\n");





	//==============================================================
	// 
	cout << "\n\nZAD 2: KOPIOWANIE\n";
	vector<int> Vec2 = { 1,2,3,4,5,6,7,8,9,10 };
	deque<int> Deq2new;

	/* Kopiowanie z Vec2 */
	/* Przydatna funkcja dodająca na koniec pojemników: back_inserter - użyte też w przykładzie */
	/* a)  skopiuj 5 elementow z Vec2 ZACZYNAJAC od czwartego do nowego obiektu Deq2new*/
	Deq2new.resize(5);
	copy_n(Vec2.begin() + 3, 5,Deq2new.begin());
	drukuj(Deq2new);
	cout << "\tOdp: {4,5,6,7,8} \n";

	/* b)  DOLÓŻ na koniec (przekopiuj) do Deq2new od drugiego do czwartego elementu  z Vec2*/
	copy(Vec2.begin() + 1, Vec2.begin()+4, back_inserter(Deq2new));
	drukuj(Deq2new);
	cout << "\tOdp: {4,5,6,7,8,2,3,4} \n";


	/* c) Zwiększ rozmiar kolejki o 3 (wykorzystaj metody resize() i size())
	Następnie wykorzystając algorytm copy_backward skopiuj z Vec2 pięć pierwszych
	elementów wstawiając od końca zwiększonej kolejki Deq2new.

	Spróbuj przewidzieć jak będzie wyglądała teraz ta kolejka.*/
	Deq2new.resize(Deq2new.size() + 3);
	copy_backward(Vec2.begin(), Vec2.begin() + 5, Deq2new.end());
	drukuj(Deq2new);
	cout << "\tDeq2new po wykorzystaniu copy_backward \n";

	/* d) Dokonaj rotacji w kontenerze (zamiany miejscami) w Deq2new,
	tak aby 5 ostatnich elementów, znalazło się na początku */
	rotate(Deq2new.begin(), Deq2new.end()-5, Deq2new.end());
	drukuj(Deq2new);
	cout << "\tOdp: {1,2,3,4,5,4,5,6,7,8,2} \n";





	//==============================================================
	// Zad 3
	cout << "\n\nZAD 3: METODY/FUNKCJE\n";

	/* a) Stwórz wektor Tab3 (w tym zadaniu proszę go nie modyfikować)
	zawierający elementy typu MojeTrio. Pojemność wektora wyosi pojVec3 = 200000.
	Wypełnij go liczbami od 0 do pojVec3-1, wykorzystaj do tego: algorytm generate_n() oraz wyrażenie lambda ze zmienianą wartością zmiennej globalnej  */
	int pojVec3 = 200000;
	vector<MojeTrio> Tab3(pojVec3);
	generate_n(Tab3.begin(), pojVec3 , [pojVec3]() mutable {return 200000-(pojVec3--); });

	cout << "Tab3[0]=" << Tab3[0] << ("\t (odp: 0)\n");
	cout << "Tab3[end-1]=" << Tab3[pojVec3-1] << "\t (odp: " << pojVec3-1 << ")\n";
	cout << "Tab3[17]=" << Tab3[17] << ("\t (odp: 17)\n");



	/* b) Przemieszaj Tab3 odpowiednim algorytmem, możesz wykorzystać
	do tego gotowe funkcje z std*/

	cout << "\tPrzemieszane Tab3: \n";
	random_shuffle(Tab3.begin(), Tab3.end());
	cout << "Tab3[0]=" << Tab3[0] << endl;
	cout << "Tab3[end-1]=" << Tab3[pojVec3 - 1] << endl;
	cout << "Tab3[17]=" << Tab3[17] << endl;


	/* c) Posortuj Tab3 wstawiając od razu do nowego wektora Vec3new
	(bez wcześniejszego przekopiowywania).
	Do sortowania wykorzystuj funkcję globalną, wyrażenie lambda oraz obiekt funkcyjny.
	Porównaj czasy. Możesz spróbować zmienić w get_tosort(), zwracany obiekt,
	tak, że wektor będzie sortowany biorąc pod uwagę różne kryteria. */
	cout << "\n SORTOWANIE\n";
	vector<MojeTrio> Vec3new(pojVec3);




	/* Mierzenie czasu na podstawie
	https://bulldogjob.pl/news/1474-jak-mierzyc-czas-wykonania-programu-w-c-c  	*/


	cout << "\nFunkcja globalna\n";
	auto begin = std::chrono::high_resolution_clock::now();
	// .............  sortowanie
	partial_sort_copy(Tab3.begin(), Tab3.end(), Vec3new.begin(), Vec3new.end(),sorting);
	cout << "Vec3new[0]=" << Vec3new[0] << ("\t (odp: 0)\n");
	cout << "Vec3new[end-1]=" << Vec3new[pojVec3 - 1] << "\t (odp: " << pojVec3 - 1 << ")\n";
	cout << "Vec3new[17]=" << Vec3new[17] << ("\t (odp: 17)\n");
	// Stop measuring time and calculate the elapsed time
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);




	cout << "\nWyrażenie Lambda\n";
	begin = std::chrono::high_resolution_clock::now();
	// .............  sortowanie
	partial_sort_copy(Tab3.begin(), Tab3.end(), Vec3new.begin(), Vec3new.end(), [](MojeTrio a, MojeTrio b) {return a.get_tosort(1) < b.get_tosort(1); });
	cout << "Vec3new[0]=" << Vec3new[0] << ("\t (odp: 0)\n");
	cout << "Vec3new[end-1]=" << Vec3new[pojVec3 - 1] << "\t (odp: " << pojVec3 - 1 << ")\n";
	cout << "Vec3new[17]=" << Vec3new[17] << ("\t (odp: 17)\n");
	// Stop measuring time and calculate the elapsed time
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);


	cout << "\nObiekt funkcyjny\n";
	begin = std::chrono::high_resolution_clock::now();
	// .............  sortowanie
	partial_sort_copy(Tab3.begin(), Tab3.end(), Vec3new.begin(), Vec3new.end(), sorting2());
	cout << "Vec3new[0]=" << Vec3new[0] << ("\t (odp: 0)\n");
	cout << "Vec3new[end-1]=" << Vec3new[pojVec3 - 1] << "\t (odp: " << pojVec3 - 1 << ")\n";
	cout << "Vec3new[17]=" << Vec3new[17] << ("\t (odp: 17)\n");
	// Stop measuring time and calculate the elapsed time
	end = std::chrono::high_resolution_clock::now();
	elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);



	//==============================================================
	// Zad 4
	cout << "\n\nZAD 4:\n";
	cout << "Sortowanie Tab3 wzgledem a\n";

	deque< MojeTrio> Poj4;
	Poj4.resize(10);
	// kod: sortowanie Tab3 wzgledem a
	sort(Tab3.begin(), Tab3.end(), Chose_sorting(Chose_sorting::By_int));
	// kod: kopiowanie 10 pierwszych elementow do Poj4 (wstawianie na POCZATEK KOLEJKI)
	copy(Tab3.begin(), Tab3.begin() + 10, Poj4.begin());
	drukuj(Poj4, 1);


	cout << "\n\nSortowanie Tab3 wzgledem b\n";
	Poj4.clear(); /* czyszczenie pojemnika */
	Poj4.resize(10);
	// kod: sortowanie Tab3 wzgledem b
	sort(Tab3.begin(), Tab3.end(), Chose_sorting(Chose_sorting::By_double));
	// kod: kopiowanie 10 pierwszych elementow do Poj4 (wstawianie na POCZATEK KOLEJKI)
	copy(Tab3.begin(), Tab3.begin() + 10, Poj4.begin());
	drukuj(Poj4, 1);


	cout << "\n\nSortowanie Tab3 wzgledem sumy\n";
	Poj4.clear(); /* czyszczenie pojemnika */
	Poj4.resize(10);
	// kod: sortowanie Tab3 wzgledem sumy
	sort(Tab3.begin(), Tab3.end(), Chose_sorting(Chose_sorting::By_float));
	// kod: kopiowanie 10 pierwszych elementow do Poj4 (wstawianie na POCZATEK KOLEJKI)
	copy(Tab3.begin(), Tab3.begin() + 10, Poj4.begin());
	drukuj(Poj4, 1);



	cout << "\n\n================\n";
	cout << "Koniec programu \n";



}


