
/* math (system_art): lin. Ausgleichsproblem loesen; A.R.T. GmbH 22.10.99-9.5.03
 * Gemeinsamer Code fuer Linux- und NT-Systeme
 *
 * Versionen:
 * v0.2 (22.10.99, KA): neu
 *   p1 (22.11.99, KA): Ausgabe Residuum
 */


#ifndef LINEAR_LSQ_H
#define LINEAR_LSQ_H

#define LINEAR_LSQ_MAX_COLUMN   10  // Max. Anzahl Spalten der Matrix mat (Anzahl Unbekannter)

// Lineares Ausgleichsproblem  mat * erg = vec  loesen:
//   - ueberschreibt mat und vec!!
// erg (o): approx. Ergebnis-Vektor (ncol Werte)
// vec (io): Vektor der Beobachtungen (nrow Werte)
// mat (io): Funktional (Matrix mit nrow Zeilen und ncol Spalten, zeilenweise im Array)
// nrow, ncol (i): Dimensionen des Problems (s.o.); nrow > ncol
// resid (o): Residuum (d.h. Norm Residuums-Vektor)
// Rueckgabe (o): 0 ok, Fehler sonst

int linear_lsq_solve(double* erg, double* vec, double* mat, int nrow, int ncol,
                     double* resid);


#endif // LINEAR_LSQ_H
