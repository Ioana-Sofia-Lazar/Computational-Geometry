/*Se dau 4 puncte in ordine.
 a. Sa se decida daca formeaza un patrulater convex.
 b. Se da un al 5-lea punct. Sa se decida daca apartine infasuratorii convexe a celor 4 puncte.

 http://www.infoarena.ro/notiuni-de-geometrie-si-aplicatii?revision=60
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");

struct Point{
    int x, y;
}A, B, C, D, P;

int orientationTest(Point A, Point B, Point C){ //produs vectorial; <0 => viraj la dr; >0 => viraj la stg
    return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

bool Convex(Point A, Point B, Point C, Point D){//verifica daca punctele in ordine formeaza un patrulater convex
    //vedem daca avem numai viraje la dreapta; daca da => patrulater convex
    return (orientationTest(A, B, C) < 0) && (orientationTest(B, C, D) < 0) && (orientationTest(C, D, A) < 0);
}

bool pInTriangle(Point A, Point B, Point C, Point P){//verifica daca punctul P se afla in interiorul triunghiului ABC
    if (orientationTest(A, B, P) > 0 && orientationTest(B, C, P) > 0 && orientationTest(C, A, P) > 0) return true;
    if (orientationTest(A, B, P) < 0 && orientationTest(B, C, P) < 0 && orientationTest(C, A, P) < 0) return true;
    return false;
}

bool apartineInfConv(Point A, Point B, Point C, Point D, Point P){//verifica daca P apartine infasuratorii convexe a punctelor A, B, C, D
    //daca P se alfa intr-unul din cele 4 triunghiuri formate de punctele date, atunci apartine infasuratorii convexe
    return (pInTriangle(A, B, C, P) || pInTriangle(B, C, D, P) || pInTriangle(C, D, A, P));
}

int main()
{
    f >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y >> P.x >> P.y;
    if(Convex(A, B, C, D)) cout << "Patrulaterul este convex\n";
        else cout << "Patrulaterul NU este convex\n";

    if (apartineInfConv(A, B, C, D, P)) cout << "P apartine infasuratorii convexe a celor 4 puncte";
        else cout << "P NU apartine infasuratorii convexe a celor 4 puncte";
    return 0;
}
