// pk3_21_lab04_kontenery.cpp :
// Autor: dr inż. Jolanta Kawulok
// ver 1

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
#include <deque>
#include <forward_list>
#include <chrono>       // std::chrono::system_clock
#include <ctime>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
////

using namespace std;

int main()
{
	/* Mierzenie czasu na podstawie
	https://bulldogjob.pl/news/1474-jak-mierzyc-czas-wykonania-programu-w-c-c   */

	int Uruchomzad = 1; // nr zad 1-4 do uruchomienia

	if (Uruchomzad == 1) {
		/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++    Porówywanie czasu wstawiania do kontenerów oraz dostepu do danych ++++++++++++++++++++++
		+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

		int poj = 1000;
		int a = 800, b = 900; // dane do spr zawartosci kontenerow
		//int a = 8, b = 9; // prosze spr dla dwoch zestawów

		/* W ćwiczeniu będziemy tworzyć tablicę wielkości poj x poj, zawierającą tabliczkę mnożenia.
		W tym celu należy wykorzystać 4 rodzaje kontnerów:
		a) wektor wektorow typu int
		b) deque deque typu int
		c) liste list typu int
		d) forward_list  forward_list   typu int    */

		/* 1.1 Proszę zmierzyc czas tworzenia wyzej wymienionych obiektow.
		a) Czy jest roznica w czasie tworzenia kontenra,
		jesli dla vector i deque bedziemy wykorzystywac push_back,
		a jesli z góry ustaloną wartość ? */

		/* ===============================================================================================
		===========================  vector =============================================================
		=================================================================================================== */
		auto begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie wektora (push_back)\n";
		vector<vector<int> > vec1;
		for (int i = 0; i < poj; i++)
		{
			vector<int> tmp;
			for (int j = 0; j < poj; j++)
			{
				tmp.push_back(i * j);
			}
			vec1.push_back(tmp);
		}

		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do wektora(push_back): %.3f s.\n", elapsed.count() * 1e-9);

		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie wektora (ustalona wartosc)\n";
		vector<vector<int> > vec2;
		vec2.resize(poj, vector<int>(poj));
		for (int i = 0; i < poj; i++)
		{
		  for (int j = 0; j < poj; j++)
		  {
		      
		      vec2[i][j] = i * j;
		
		  }
		}
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do vectora (ustalona wartosc): %.3f s.\n", elapsed.count() * 1e-9);
		/* ================================================================================================
		===========================  DEQUE ================================================================
		=================================================================================================== */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie deque(push_back)\n";
		deque<deque<int>> deq1;
		for (int i = 0; i < poj; i++)
		{
			deque<int> tmp1;
			for (int j = 0; j < poj; j++)
			{
				tmp1.push_back(i * j);
			}
			deq1.push_back(tmp1);
		}

		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do deque(push_back): %.3f s.\n", elapsed.count() * 1e-9);

		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie deque(ustalona wartosc)\n";
		deque<deque<int>> deq2(poj, deque<int>(poj));
		
		for (int i = 0; i < poj; i++)
		{
			for (int j = 0; j < poj; j++)
			{

				deq2[i][j] = i * j;

			}
		}
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do deque(ustalona wartosc): %.3f s.\n", elapsed.count() * 1e-9);
		/*   ================================================================================================
			===========================  list ================================================================
			================================================================================================= */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie LIST\n";
		list<list<int>> list1;

		for (int i = 1; i <= poj; i++)
		{
			list<int> tmp2;
			for (int j = 1; j <= poj; j++)
			{
				tmp2.push_back(i * j);
			}
			list1.push_back(tmp2);
		}

		// Stop measuring time and calculate the elapsed time
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do list: %.3f s.\n", elapsed.count() * 1e-9);

		/*   ==============================================================================================
		===========================  forward_list =========================================================
		==================================================================================================== */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie forward_list\n";
		forward_list<forward_list<int>> flist1;
		for (int i = poj; i >= 1; i--)
		{
			forward_list<int> tmp3;
			for (int j = poj; j >= 1; j--)
			{
				tmp3.push_front(i * j);
			}
			flist1.push_front(tmp3);
		}

		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do forward_list: %.3f s.\n", elapsed.count() * 1e-9);

		/*   =============================================================================================
		1.2 Proszę odczytac wartosci z tabeli dla par a i b (czyli wynikiem jest a*b)
		Dla list i forward_list prosze dodatkowo zmierzyc czas.
		Proszę zwrócić uwagę na różnice czasowe przy wykorzystaniu innych wartości a i b
		(zdefiniowanych na początku zad 1).
		 ================================================================================================= */
		cout << "\n\n\tOdczyt z kontenerow: \n";
		cout << "\nVEC: " << vec1[a][b];
		cout << "\nDEQ: " << deq1[a][b] << "\n";

		/*   ============================================================================================
		===========================  list ===============================================================
		==============================================================================================*/
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nlist: ";
		for (list<list<int> >::const_iterator i = list1.begin(); i != list1.end(); i++)
		{
			if (i->front() == a)
			{
				for (list<int>::const_iterator j = next(i->begin()); j != i->end(); j++)
				{
					if (a * b == *j)
						cout << *j << endl;
				}
			}
		}

		//cout << "\nlist: ";

		// Stop measuring time and calculate the elapsed time
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("\nCzas odczytu z list: %.3f s.\n", elapsed.count() * 1e-9);

		/*   ============================================================================================
		===========================  forward_list =======================================================
		=============================================================================================== */
		begin = std::chrono::high_resolution_clock::now();

		cout << "\nforward: ";
		for (forward_list<forward_list<int> > ::const_iterator i = flist1.cbegin(); i != flist1.cend(); i++)
		{
			if (i->front() == a)
			{
				for (forward_list<int>::const_iterator j = next(i->cbegin()); j != i->cend(); j++)
				{
					if (a * b == *j)
					{
						cout << *j << endl;
					}
				}
			}
		}

		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("\nCzas odczytu z forward_list: %.3f s.\n", elapsed.count() * 1e-9);
	}

	if (Uruchomzad == 2) {
		/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			++++++++++++++++++++ zad 2 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			++++++++++++++++++++++++++++++++ ADAPTORY ++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

			/* Prosze stworzyc 3 rodzaje adaptorów typu int:
			stack, queue, priority_queue
			do których prosze dodawac pokolei dane z myvec
			(dla priority_queue definicja prorytetu nie ma znaczenia).
			A następnie prosze wyswietlic zawartosci tych obiektów      */

		vector<int> myvec = { 1 ,10 ,2 ,20, 3, 30 };

		stack<int> stacked1;
		for (int i = 0; i != myvec.size(); i++)
		{
			stacked1.push(myvec[i]);
		}
		queue<int> queue1;
		for (int i = 0; i != myvec.size(); i++)
		{
			queue1.push(myvec[i]);
		}
		priority_queue<int> prioQue1;
		for (int i = 0; i != myvec.size(); i++)
		{
			prioQue1.push(myvec[i]);
		}
		cout << "Wyswietlanie stosu \n";
		while (!stacked1.empty())
		{
			cout << stacked1.top() << " ";
			stacked1.pop();
		}
		cout << endl;
		cout << "Wyswietlanie kolejki \n";
		while (!queue1.empty())
		{
			cout << queue1.front() << " ";
			queue1.pop();
		}
		cout << endl;
		cout << "Wyswietlanie kolejki priorytetowej \n";
		while (!prioQue1.empty())
		{
			cout << prioQue1.top() << " ";
			prioQue1.pop();
		}
	}

	if (Uruchomzad == 3) {
		/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++++++ Kontenery asocjacyjne  ++++++++++++++++++++++++++++++++++++++++ */

		vector<int> vec3 = { 1,2,3,4,5,5,4,3,2,1,0,10,11,12,13,14,15,-1,-2,-3,-4,-5,15,14,13,12,11,10 };

		/* zad 3.1 Proszę stworzyc obiekt typu set, multiset, map oraz multimap typu int,
		a następnie (dla dwóch pierwszych) dodać do nich zawartość wektora vec3.
		Dla map proszę wstawiać rowniez zawartość wektora, przy czym kluczem niech będzie wartość
		bewzględna danego elmentu (mozna wykorzystać abs i pair).
		Dodawanie do 4 kontenetow można wykonac w 1 pętli.        */
		set<int> set1;
		multiset<int> mset1;
		map<int, int>map1;
		multimap<int, int>mmap1;
		/* Nastepnie proszę wyswietlic zawartosc tych 4 obiektow.*/
		for (int i = 0; i < vec3.size(); i++)
		{
			set1.insert(vec3[i]);
			mset1.insert(vec3[i]);
			map1.insert(pair<int, int>(abs(vec3[i]), vec3[i]));
			mmap1.insert(pair<int, int>(abs(vec3[i]), vec3[i]));
		}

		cout << "\nZAWARTOSC set\n";
		set<int, greater<int> >::iterator itr1;
		for (itr1 = set1.begin(); itr1 != set1.end(); itr1++)
		{
			cout << *itr1 << " ";
		}
		cout << "\n\nZAWARTOSC multiset\n";
		multiset<int, greater<int> >::iterator itr2;
		for (itr2 = mset1.begin(); itr2 != mset1.end(); itr2++)
		{
			cout << *itr2 << " ";
		}

		cout << "\n\nZAWARTOSC map\n";
		map<int, int>::iterator itr3;
		for (itr3 = map1.begin(); itr3 != map1.end(); itr3++)
		{
			cout << itr3->first << " " << itr3->second << endl;
		}

		cout << "\n\nZAWARTOSC multimap\n";
		multimap<int, int>::iterator itr4;
		for (itr4 = mmap1.begin(); itr4 != mmap1.end(); itr4++)
		{
			cout << itr4->first << " " << itr4->second << endl;
		}

		/* =====================================================================
		===================== zad 3.1 ==========================================
		Dla MULTIMAP proszę usunąć WSZYSTKIE elementy gdzie klucz wynosi 2     */
		cout << "\n\nZAD 3.1 multimap po usunieciu 2\n";
		mmap1.erase(2);
		for (itr4 = mmap1.begin(); itr4 != mmap1.end(); itr4++)
		{
			cout << itr4->first << " " << itr4->second << endl;
		}

		/* =====================================================================
		===================== zad 3.2 ==========================================
			 Proszę swtorzyć inną zwykłą mapę (nie multi),
			 a następnie przepisać z wyzej stworzonej multimapy zawartość tak, aby:
			 klucze były niemniejsze niż 10 oraz
			 klucze byly mniejsze od 14.
			 Natępnie prosze wyswietlic tę nową mapę. */
		map<int, int> map2;
		for (itr4 = mmap1.begin(); itr4 != mmap1.end(); itr4++)
		{
			if (itr4->first >= 10 && itr4->first < 14)
			{
				map2.insert(pair<int, int>(itr4->first, itr4->second));
			}
		}
		cout << "\n\nZAD 3.2 Nowa mapa na podstawie multimapy \n";
		for (itr3 = map2.begin(); itr3 != map2.end(); itr3++)
		{
			cout << itr3->first << " " << itr3->second << endl;
		}
	}

	if (Uruchomzad == 4) {
		/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++++++ unordered_map  +++++++++++++++++++++++++++++++++++++++++++++++ */

		/* Stworz unordered_map<string, string>, a nastepnie wstaw do niego dowolne pary wyrazow.
		Nastepnie sprawdz, co pod dwoma wybranymi kluczami sie znajduje.
		Niech jeden z kluczy rzeczywiscie znajduje sie w bazie
		(wtedy prosze wyswietlic ten element),
		a niech drugiego klucza nie ma
		(wtedy prosze wyswietlic informacje, ze nie znaleziono danego klucza w mapie). */
		unordered_map<string, string> unMap1;
		unordered_map<string, string>::iterator itr5;
		string Unlock;
		unMap1["Key"] = "This value exist";
		cout << "Insert a key: ";
		cin >> Unlock;
		cout << endl;
		if (unMap1.find(Unlock) != unMap1.end())
		{
			for (itr5 = unMap1.begin(); itr5 != unMap1.end(); itr5++)
			{
				if (itr5->first == "Key")
				{
					cout << itr5->first << " | " << itr5->second << endl;
				}
			}
		}
		else
		{
			cout << "This Key doesn't exist in database!" << endl;
		}
	}
}