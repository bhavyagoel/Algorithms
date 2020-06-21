import java.util.Scanner;
import java.util.Arrays; 


public class StrassenMatrixMulti {
    
    public static int[][] MatrixMultiply(int arrayA[][], int arrayB[][], int rowA, int colA, int rowB, int colB) {
        int arrayC[][] = new int[rowA][colB];

        for (int i = 0 ; i < rowA ; i++) {
            for(int j = 0 ; j < colB ; j++) {
                arrayC[i][j] = 0;
                for (int k = 0 ; k < colA ; k++) {
                    arrayC[i][j] += arrayA[i][k] * arrayB[k][j];
                }
            }
        }

        return arrayC;

    }

    public static int[][] Strassen(int arrayA[][], int arrayB[][], int rowA, int colA, int rowB, int colB) {
        if (rowA == 1 || colA == 1 || colB == 1) {
            return MatrixMultiply(arrayA, arrayB, rowA, colA, rowB, colB)
        }

        int arrayC[][] = new int[rowA][colB];

        int adjN = (rowA >> 1) + (rowA & 1);
        int adjL = (colA >> 1) + (colA & 1);
        int adjM = (colB >> 1) + (colB & 1);

        int As[][][][] = new int[2][2][adjN][adjM];

        for (int i = 0 ; i < 2 ; i++) {
            for (int j = 0 ; j < 2 ; j++) {
                for (int k = 0 ; k < adjN ; k++) {
                    for (int l = 0 ; l < adjL ; l++) {
                        int K = k + (i & 1) * adjN;
                        int L = l + (j & 1) * adjL;

                        As[i][j][k][l] = (K < rowA && L < colA) ? arrayA[K][L] : 0 ;
                    }
                }
            }
        }

        int Bs[][][][] = new int[2][2][adjN][adjM];

        for (int i = 0 ; i < 2 ; i++) {
            for (int j = 0 ; j < 2 ; j++) {
                for (int k = 0 ; k < adjL ; k++) {
                    for (int l = 0 ; l < adjM ; l++) {
                        int K = k + (i & 1) * adjL;
                        int L = l + (j & 1) * adjM;

                        Bs[i][j][k][l] = (K < rowA && L < colA) ? arrayB[K][L] : 0 ;
                    }
                }
            }
        }

        int s[][][][] = new int[10][][][];

        for (int i = 0; i < 10 ; i++) {
            switch(i) {
                case 0:
                    s[i] = new int[adjM][][];
                    for (int j = 0 ; j < adjL ; j++) {
                        s[i][j] = new int[adjM][];
                        for (int k = 0 ; k < adjM ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = Bs[0][1][j][k] - Bs[1][1][j][k];
                        }
                    }
                    break;
                case 1:
                    s[i] = new int[adjN][][];
                    for (int j = 0 ; j < adjN ; j++) {
                        s[i][j] = new int[adjL][];
                        for (int k = 0 ; k < adjL ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = As[0][0][j][k] + As[0][1][j][k];
                        }
                    }
                    break;
                case 2:
                    s[i] = new int[adjN][][];
                    for (int j = 0 ; j < adjN ; j++) {
                        s[i][j] = new int[adjL][];
                        for (int k = 0 ; k < adjL ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = As[1][0][j][k] + As[1][1][j][k];
                        }
                    }
                    break;
                case 3:
                    s[i] = new int[adjL][][];
                    for (int j = 0 ; j < adjL ; j++) {
                        s[i][j] = new int[adjM][];
                        for (int k = 0 ; k < adjM ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = Bs[1][0][j][k] - Bs[0][0][j][k];
                        }
                    }
                    break;
                case 4:
                    s[i] = new int[adjN][][];
                    for (int j = 0 ; j < adjN ; j++) {
                        s[i][j] = new int[adjL][];
                        for (int k = 0 ; k < adjL ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = As[0][0][j][k] + As[1][1][j][k];
                        }
                    }
                    break;
                case 5:
                    s[i] = new int[adjL][][];
                    for (int j = 0 ; j < adjL ; j++) {
                        s[i][j] = new int[adjM][];
                        for (int k = 0 ; k < adjM ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = Bs[0][0][j][k] + Bs[1][1][j][k];
                        }
                    }
                    break;
                case 6:
                    s[i] = new int[adjN][][];
                    for (int j = 0 ; j < adjN ; j++) {
                        s[i][j] = new int[adjL][];
                        for (int k = 0 ; k < adjL ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = As[0][1][j][k] - As[1][1][j][k];
                        }
                    }
                    break;
                case 7:
                    s[i] = new int[adjL][][];
                    for (int j = 0 ; j < adjL ; j++) {
                        s[i][j] = new int[adjM][];
                        for (int k = 0 ; k < adjM ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = Bs[1][0][j][k] + Bs[1][1][j][k];
                        }
                    }
                    break;
                case 8:
                    s[i] = new int[adjN][][];
                    for (int j = 0 ; j < adjN ; j++) {
                        s[i][j] = new int[adjL][];
                        for (int k = 0 ; k < adjL ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = As[0][0][j][k] - As[1][0][j][k];
                        }
                    }
                    break;
                case 9:
                    s[i] = new int[adjL][][];
                    for (int j = 0 ; j < adjL ; j++) {
                        s[i][j] = new int[adjM][];
                        for (int k = 0 ; k < adjM ; k++) {
                            s[i][j][k] = new int[1];
                            s[i][j][k][0] = Bs[0][0][j][k] + Bs[0][1][j][k];
                        }
                    }
                    break;
            }
        }

        int p[][][][] = new int[7][][][];
    }

    public static void main(String[] args) {

    }
}