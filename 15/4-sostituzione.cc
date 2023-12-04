#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Usage: sostituzione <input_file> <lettera>" << endl;
        exit(0);
    }

    fstream input;
    char    lettera = argv[2][0];

    input.open(argv[1], ios::in);

    if (input.fail())
    {
        cout << "Il file dato in input " << argv[1] << " non esiste!" << endl;
    }

    char carattere;

    while (input.get(carattere))
    {
        if (carattere == lettera)cout << "?";
        else cout << carattere;
    }

    input.close();

    return 0;
}
