//Autor: Krzysztof Piatkowski




#include "pch.h"


const char* GridForP1[BOARD_SIZE][BOARD_SIZE];
const char* GridForP2[BOARD_SIZE][BOARD_SIZE];
const char* ShadowGridForP1[BOARD_SIZE][BOARD_SIZE];
const char* ShadowGridForP2[BOARD_SIZE][BOARD_SIZE];
int x, y;
int P1ShipsToDeploy = 10;
int P2ShipsToDeploy = 10;
int P1ShipsPoints = 0;
int P2ShipsPoints = 0;


void Initialize();//funkcja tworzy wszystkie 4 tablice i wypelnia je "polami wody" O
void SystemClear();//funkcja czyœci ekran
void P1PrintBoard();//funkcja wypisuje na ekran plansze gracza 1
void P2PrintBoard();//funkcja wypisuje na ekran plansze gracza 2
void CoordsDeclaration();//funkcja pozwala na okreslenia polozenia kolumna/wiersz
void ShipDirectionDeclaration(char &PlayerDirection);//funkcja pozwala na okreslenie polozenia lewo,prawo,gora,dol
void FourFrameForP1Declaration();//wszystkie funkcje do komentarza opisuja rozmieszczenie i poprawnosc rozmieszczenia poszczegolnych statkow
void FourFrameForP2Declaration();
void ThreeFrameForP1Declaration();
void ThreeFrameForP2Declaration();
void TwoFrameForP1Declaration();
void TwoFrameForP2Declaration();
void OneFrameForP1Declaration();
void OneFrameForP2Declaration();//koniec opisu wszystkich funkcji
void SetShipsForP1();//funkcja pozwala ustalic polozenie statkow dla gracza 1
void SetShipsForP2();//funkcja pozwala ustalic polozenie statkow dla gracza 2
void P1Turn();//funkcja opisuje ture gracza 1
void P2Turn();//funkcja opisuje ture gracza 2
void Game();//funkcja juz samej gry, trwa do momentu az ktorys z graczy nie zatopi wszystkich statkow

int main()
{

	Initialize();
	cout << "Witajcie w grze Battleships!\n";
	cout << "Jest to klasyczna gra oparta na prostym zalozeniu, zatopic statki przeciwnika\n";
	cout << "Kazdy z was ma do rozstawienia 10 statkow, do dyspozycji jest plansza o wielkosci 10x10\n";
	cout << "Statki maja nastepujaca wielkosc oraz sa do rozstawienia w nastepujacych ilosciach:\n";
	cout << "Czteromasztowiec - 1 statek\n";
	cout << "Trzymasztowiec - 2 statki\n";
	cout << "Dwumasztowiec - 3 statki\n";
	cout << "Jednomasztowiec - 4 statki\n";
	Sleep(12200);
	cout << "Zaczynamy!\n";
	Sleep(2200);
	SetShipsForP1();
	Sleep(8000);
	SetShipsForP2();
	Sleep(8000);

	Game();


	system("pause");
}

void Initialize()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int k = 0; k < BOARD_SIZE; k++) {
			GridForP1[i][k] = "O"; //zawiera same statki gracza 1, tj. lokalizacje jego statkow
			GridForP2[i][k] = "O"; //zawiera same statki gracza 2
			ShadowGridForP1[i][k] = "O";//zawiera plansze trafien dla gracza 1, tj. gdzie trafial i w co
			ShadowGridForP2[i][k] = "O";//zawiera plansze trafien dla gracza 2
		}
	}
}
void SystemClear() {
	std::system("CLS");
}
void P1PrintBoard()
{
	cout << "\n    ";
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << std::setw(2) << i + 1 << "  ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << std::setw(2) << i + 1 << "  ";
		for (int k = 0; k < BOARD_SIZE; k++) {
			cout << std::setw(2) << GridForP1[k][i] << "  ";

		}
		cout << endl;
	}
}
void P2PrintBoard()
{
	cout << "\n    ";
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << std::setw(2) << i + 1 << "  ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << std::setw(2) << i + 1 << "  ";
		for (int k = 0; k < BOARD_SIZE; k++) {
			cout << std::setw(2) << GridForP2[k][i] << "  ";

		}
		cout << endl;
	}
}
void CoordsDeclaration()
{
	cout << "Podaj wiersz w ktorym ma byc punkt statku: ";
	while (!(cin >> x) || (x > 10 || x < 1)) {
		cout << "Zle wprowadzona zmienna sprobuj ponownie: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	cout << "Podaj kolume w ktorej ma byc punkt statku: ";
	while (!(cin >> y) || (y > 10 || y < 1)) {
		cout << "Zle wprowadzona zmienna sprobuj ponownie: ";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}



void ShipDirectionDeclaration(char &PlayerDirection)
{
	cout << "Podaj kierunek (lewo,prawo,gora,dol) w jakim ma znajdowac sie statek:\n";
	cout << "wpisz dla:\n lewo - l \n prawo - p \n gora - g \n dol - d \n";
	cin >> PlayerDirection;

	while (PlayerDirection != 'l' && PlayerDirection != 'p' && PlayerDirection != 'g' && PlayerDirection != 'd') {
		cout << "Zle podales kierunek, sprobuj ponownie: ";
		cout << "wpisz dla:\n lewo - l \n prawo - p \n gora - g \n dol - d \n";
		cin >> PlayerDirection;
	}

}



void FourFrameForP1Declaration() {
	char Direction;
	cout << "Umiesc statek o dlugosci czterech pol\n\n";
	ShipDirectionDeclaration(Direction);
	CoordsDeclaration();
	switch (Direction) {
	case 'l':
		if (((y - 5) < -1)) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 2][x - 1] = "S";
			GridForP1[y - 3][x - 1] = "S";
			GridForP1[y - 4][x - 1] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'p':
		if ((y + 4) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y][x - 1] = "S";
			GridForP1[y + 1][x - 1] = "S";
			GridForP1[y + 2][x - 1] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'g':
		if ((x - 5) < -1) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 1][x - 2] = "S";
			GridForP1[y - 1][x - 3] = "S";
			GridForP1[y - 1][x - 4] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'd':
		if ((x + 4) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 1][x] = "S";
			GridForP1[y - 1][x + 1] = "S";
			GridForP1[y - 1][x + 2] = "S";
			P1ShipsToDeploy--;
			break;
		}
	default:
		break;
	}

}

/**************************************************/

void FourFrameForP2Declaration() {
	char Direction;
	cout << "Umiesc statek o dlugosci czterech pol\n\n";
	ShipDirectionDeclaration(Direction);
	CoordsDeclaration();
	switch (Direction) {
	case 'l':
		if (((x - 5) < -1)) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 2][x - 1] = "S";
			GridForP2[y - 3][x - 1] = "S";
			GridForP2[y - 4][x - 1] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'p':
		if ((x + 4) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y][x - 1] = "S";
			GridForP2[y + 1][x - 1] = "S";
			GridForP2[y + 2][x - 1] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'g':
		if ((y - 5) < -1) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 1][x - 2] = "S";
			GridForP2[y - 1][x - 3] = "S";
			GridForP2[y - 1][x - 4] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'd':
		if ((y + 4) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 1][x] = "S";
			GridForP2[y - 1][x + 1] = "S";
			GridForP2[y - 1][x + 2] = "S";
			P2ShipsToDeploy--;
			break;
		}
	default:
		break;
	}

}

/**************************************************/

void ThreeFrameForP1Declaration() {
	char Direction;
	cout << "Umiesc statek o dlugosci trzech pol\n\n";
	ShipDirectionDeclaration(Direction);
	CoordsDeclaration();
	switch (Direction) {
	case 'l':
		if (((y - 4) < -1)) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 2][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 3][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 2][x - 1] = "S";
			GridForP1[y - 3][x - 1] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'p':
		if ((y + 3) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y + 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y][x - 1] = "S";
			GridForP1[y + 1][x - 1] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'g':
		if ((x - 4) < -1) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 1][x - 2] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 1][x - 3] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 1][x - 2] = "S";
			GridForP1[y - 1][x - 3] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'd':
		if ((x + 3) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 1][x] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 1][x + 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 1][x] = "S";
			GridForP1[y - 1][x + 1] = "S";
			P1ShipsToDeploy--;
			break;
		}
	default:
		break;
	}

}

/**************************************************/

void ThreeFrameForP2Declaration()
{
	char Direction;
	cout << "Umiesc statek o dlugosci trzech pol\n\n";
	ShipDirectionDeclaration(Direction);
	CoordsDeclaration();
	switch (Direction) {
	case 'l':
		if (((y - 4) < -1)) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 2][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 3][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 2][x - 1] = "S";
			GridForP2[y - 3][x - 1] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'p':
		if ((y + 3) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y + 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y][x - 1] = "S";
			GridForP2[y + 1][x - 1] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'g':
		if ((x - 4) < -2) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 1][x - 2] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 1][x - 3] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 1][x - 2] = "S";
			GridForP2[y - 1][x - 3] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'd':
		if ((x + 3) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 1][x] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 1][x + 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 1][x] = "S";
			GridForP2[y - 1][x + 1] = "S";
			P2ShipsToDeploy--;
			break;
		}
	default:
		break;
	}

}

/**************************************************/

void TwoFrameForP1Declaration() {
	char Direction;
	cout << "Umiesc statek o dlugosci dwoch pol\n\n";
	ShipDirectionDeclaration(Direction);
	CoordsDeclaration();
	switch (Direction) {
	case 'l':
		if (((y - 3) < -1)) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 2][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 2][x - 1] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'p':
		if ((y + 2) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y][x - 1] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'g':
		if ((x - 3) < -1) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 1][x - 2] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 1][x - 2] = "S";
			P1ShipsToDeploy--;
			break;
		}
	case 'd':
		if ((x + 2) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP1[y - 1][x] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP1[y - 1][x - 1] = "S";
			GridForP1[y - 1][x] = "S";
			P1ShipsToDeploy--;
			break;
		}
	default:
		break;
	}

}

/**************************************************/

void TwoFrameForP2Declaration()
{
	char Direction;
	cout << "Umiesc statek o dlugosci dwoch pol\n\n";
	ShipDirectionDeclaration(Direction);
	CoordsDeclaration();
	switch (Direction) {
	case 'l':
		if (((y - 3) < -1)) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 2][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 2][x - 1] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'p':
		if ((y + 2) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y][x - 1] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'g':
		if ((x - 3) < -1) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 1][x - 2] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 1][x - 2] = "S";
			P2ShipsToDeploy--;
			break;
		}
	case 'd':
		if ((x + 2) > 11) {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else if (GridForP2[y - 1][x] == "S") {
			cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";
			break;
		}
		else {
			GridForP2[y - 1][x - 1] = "S";
			GridForP2[y - 1][x] = "S";
			P2ShipsToDeploy--;
			break;
		}
	default:
		break;
	}

}

/**************************************************/

void OneFrameForP1Declaration() {
	cout << "Umiesc statek o dlugosci jednego pola\n\n";
	CoordsDeclaration();

	if (GridForP1[y - 1][x - 1] == "S") {
		cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";

	}
	else {
		GridForP1[y - 1][x - 1] = "S";
		P1ShipsToDeploy--;
	}
}

/**************************************************/

void OneFrameForP2Declaration() {
	cout << "Umiesc statek o dlugosci jednego pola\n\n";
	CoordsDeclaration();

	if (GridForP2[y - 1][x - 1] == "S") {
		cout << "Nie mozesz ustawic statku w tym miejscu, sprobuj ponownie\n\n";

	}
	else {
		GridForP2[y - 1][x - 1] = "S";
		P2ShipsToDeploy--;
	}
}

/*******************************************************/

void SetShipsForP1()
{
	SystemClear();
	cout << "Graczu pierwszy umiesc swoje statki: \n";
	while (P1ShipsToDeploy == 10)
	{
		FourFrameForP1Declaration();
		P1PrintBoard();
	}
	while (P1ShipsToDeploy > 7) {
		ThreeFrameForP1Declaration();
		P1PrintBoard();
	}
	while (P1ShipsToDeploy > 4) {
		TwoFrameForP1Declaration();
		P1PrintBoard();
	}
	while (P1ShipsToDeploy > 0) {
		OneFrameForP1Declaration();
		P1PrintBoard();
	}
	SystemClear();
	P1PrintBoard();
}

void SetShipsForP2()
{
	SystemClear();
	cout << "Graczu drugi umiesc swoje statki: \n";
	while (P2ShipsToDeploy == 10)
	{
		FourFrameForP2Declaration();
		P2PrintBoard();
	}
	while (P2ShipsToDeploy > 7) {
		ThreeFrameForP2Declaration();
		P2PrintBoard();
	}
	while (P2ShipsToDeploy > 4) {
		TwoFrameForP2Declaration();
		P2PrintBoard();
	}
	while (P2ShipsToDeploy > 0) {
		OneFrameForP2Declaration();
		P2PrintBoard();
	}
	SystemClear();
	P2PrintBoard();
}

/**************************************************/



void P1Turn()
{
	std::system("cls");
	cout << "Graczu pierwszy, wybierz pole do trafienia" << endl;
	cout << "    ";
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << std::setw(2) << i + 1 << "  ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << std::setw(2) << i + 1 << "  ";
		for (int k = 0; k < BOARD_SIZE; k++) {
			cout << std::setw(2) << ShadowGridForP1[k][i] << "  ";

		}
		cout << endl;
	}
	CoordsDeclaration();

	if ((ShadowGridForP1[y - 1][x - 1] == "x") || (ShadowGridForP1[y - 1][x - 1] == "m")) {
		cout << "Juz tutaj strzelales!" << endl;
	}
	else {
		if (GridForP2[y - 1][x - 1] == "O") {
			cout << "Pudlo!" << endl;
			ShadowGridForP1[y - 1][x - 1] = "m";
		}
		else if (GridForP2[y - 1][x - 1] == "S") {
			cout << "Trafiles w statek przeciwnika!" << endl;
			ShadowGridForP1[y - 1][x - 1] = "x";
			P1ShipsPoints++;
			Sleep(1000);
			if (P1ShipsPoints < 20) {
				P1Turn();
			}
		}
	}
}

void P2Turn()
{
	std::system("cls");
	cout << "Graczu drugi, wybierz pole do trafienia" << endl;
	cout << "    ";
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << std::setw(2) << i + 1 << "  ";
	}
	cout << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << std::setw(2) << i + 1 << "  ";
		for (int k = 0; k < BOARD_SIZE; k++) {
			cout << std::setw(2) << ShadowGridForP2[k][i] << "  ";

		}
		cout << endl;
	}
	CoordsDeclaration();

	if ((ShadowGridForP2[y - 1][x - 1] == "x") || (ShadowGridForP2[y - 1][x - 1] == "m")) {
		cout << "Juz tutaj strzelales!" << endl;
	}
	else {
		if (GridForP1[y - 1][x - 1] == "O") {
			cout << "Pudlo!" << endl;
			ShadowGridForP2[y - 1][x - 1] = "m";
		}
		else if (GridForP1[y - 1][x - 1] == "S") {
			cout << "Trafiles statek przeciwnika!" << endl;
			ShadowGridForP2[y - 1][x - 1] = "x";
			P2ShipsPoints++;
			Sleep(1000);
			if (P2ShipsPoints < 20) {
				P2Turn();
			}
		}
	}
}


void Game()
{
	while (true)
	{

		P1Turn();
		Sleep(1000);
		if (P1ShipsPoints == 20) {
			cout << endl << "Gratulacje graczu pierwszy, wygrales gre!\n";
			break;
		}
		P2Turn();
		Sleep(1000);
		if (P2ShipsPoints == 20) {
			cout << endl << "Gratulacje graczu drugi, wygrales gre!\n";
			break;
		}
	}
}
