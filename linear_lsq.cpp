/* math (system_art): lin. Ausgleichsproblem loesen; A.R.T. GmbH 22.10.99-9.5.03
 * Gemeinsamer Code fuer Linux- und NT-Systeme
 *
 * Loest lineares Ausgleichsproblem  M * s = v  mit Least-Square-Alg.
 *
 * Versionen:
 * v0.2 (22.10.99, KA): Loesung durch Householder-Orthogonalisierung
 *   p1 (22.11.99, KA): Ausgabe Residuum
 *
 * TODO:
 *   - Ueberschreiben von Feldern vermeiden?
 */

//#define DEBUG
#pragma warning( disable: 4305 )

#include <math.h>

#include "log.h"

#include "linear_lsq.h"

#include <string>

#ifdef WIN32
//#include "calculation.h"
#endif

// Lineares Ausgleichsproblem  mat * erg = vec  loesen:
//   - ueberschreibt mat und vec!!
// erg (o): approx. Ergebnis-Vektor (ncol Werte)
// vec (io): Vektor der Beobachtungen (nrow Werte)
// mat (io): Funktional (Matrix mit nrow Zeilen und ncol Spalten, zeilenweise im Array)
// nrow, ncol (i): Dimensionen des Problems (s.o.); nrow > ncol
// resid (o): Residuum (d.h. Norm Residuums-Vektor)
// Rueckgabe (o): 0 ok, Fehler sonst

int linear_lsq_solve(double* erg, double* vec, double* mat, int nrow, int ncol,
		     double* resid)
{
	int i, j, k;
	double d[LINEAR_LSQ_MAX_COLUMN];
	double sigma, beta, s, sum;

	if(ncol > LINEAR_LSQ_MAX_COLUMN){
		#ifdef DEBUG
			printf("- linear_lsq: error too many columns %d\n", ncol);
		#endif

		return -1;
	}

	// Householder-Orthogonalisierung:

	for(i=0; i<ncol; i++){

		// Parameter fuer Householder-Schritt bestimmen:

		sigma = 0;

		for(j=i; j<nrow; j++){    // Norm einer Spalte
			s = mat[j * ncol + i];
			sigma += s * s;
		}

		if(sigma == 0){           // Matrix mat war singulaer
			#ifdef DEBUG
				log_printf("- linear_lsq: error singular matrix\n");
			#endif

			return -2;
		}

		s = d[i] = (mat[i * ncol + i] < 0) ? sqrt(sigma) : -sqrt(sigma);
		beta = 1 / (s * mat[i * ncol + i] - sigma);
		mat[i * ncol + i] -= s;

		// Householder-Trafo:

		for(j=i+1; j<ncol; j++){
			sum = 0;

			for(k=i; k<nrow; k++){
				sum += mat[k * ncol + i] * mat[k * ncol + j];
			}

			sum *= beta;

			for(k=i; k<nrow; k++){
				mat[k * ncol + j] += mat[k * ncol + i] * sum;
			}
		}

		// Trafo fuer Vector durchfuehren:

		sum = 0;

		for(k=i; k<nrow; k++){
			sum += mat[k * ncol + i] * vec[k];
		}

		sum *= beta;

		for(k=i; k<nrow; k++){
			vec[k] += mat[k * ncol + i] * sum;
		}
	}

	// Gleichungssystem aufloesen:

	for(i=ncol-1; i>=0; i--){
		erg[i] = vec[i];

		for(j=i+1; j<ncol; j++){
			erg[i] -= mat[i * ncol + j] * erg[j];
		}

		erg[i] /= d[i];
	}

	// Residuum rechnen:

	sum = 0;

	for(k=ncol; k<nrow; k++){
		sum += vec[k] * vec[k];
	}

	*resid = sqrt(sum);

	return 0;
}



