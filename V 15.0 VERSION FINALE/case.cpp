#include "case.h"

using namespace std;

Case::Case()
:Cordonnees("00"),m_libre(true)
{}

Case::Case(string _coordonnees, bool _libre)
:Cordonnees(_coordonnees),m_libre(_libre)
{}

void Case::set_libre(bool _libre) {m_libre = _libre;}
bool Case::get_libre() {return m_libre;}
