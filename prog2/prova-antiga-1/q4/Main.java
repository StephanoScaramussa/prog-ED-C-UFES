public class Main{
    public static void main(String[] args){
        int[][] mtz = new int[3][3];
        mtz[0][0] = 10;
        mtz[0][1] = 40;
        mtz[0][2] = 3;
        mtz[1][0] = 50;
        mtz[1][1] = 8;
        mtz[1][2] = 5;
        mtz[2][0] = 90;
        mtz[2][1] = 14;
        mtz[2][2] = 2;
        for(int i = 0; i < 3; i++){
            int soma = 0;
            for(int j = 0; j < 3; j++){
                soma += mtz[i][j];
            }
            System.out.println("Soma da linha " + (i+1) + ": " + soma);
        }
    }
}