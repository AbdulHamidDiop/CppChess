#include "pieces.h"
#include "echequier.h"
#include "RAIImove.h"
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QApplication>
#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef BIBLIOTHEQUE_COURS_INCLUS
    bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

    // cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.

    bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
#endif
    //NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}


Model::King* createKing(bool bOw, View::Board& board) {
    try {
        return new Model::King(bOw);
    }
    catch (const std::runtime_error& e) {
        board.showMessage("Error", e.what());
        return nullptr;
    }
}
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    initialiserBibliothequeCours(argc, argv);

    View::Board board;
    board.setWindowTitle("Echiquier");
    board.show();

    using Model::King;
    using Model::Bishop;
    using Model::Rook;

    King* whiteKing = createKing(true, board);
    King* blackKing = createKing(false,board);

    Bishop* whiteBishop = new Bishop(true);
    Bishop* blackBishop = new Bishop(false);

    Rook* whiteRook = new Rook(true);
    Rook* blackRook = new Rook(false);

    board.placePiece(0, 3, blackKing);
    board.placePiece(7, 3, whiteKing);

    board.placePiece(0, 2, blackBishop);
    board.placePiece(7, 2, whiteBishop);

    board.placePiece(0, 5, blackBishop);
    board.placePiece(7, 5, whiteBishop);

    board.placePiece(0, 0, blackRook);
    board.placePiece(7, 0, whiteRook);

    board.placePiece(0, 7, blackRook);
    board.placePiece(7, 7, whiteRook);

    return app.exec();
}