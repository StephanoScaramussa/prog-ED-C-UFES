public class Main{
    public static void main(String[] args){
        int[] numeros = {1,2,3,1,2,3,1,2,3};
        int chave = 3;
        for(int i = 0; i<numeros.length; i++){
            if(numeros[i]==chave){
                System.out.println("Indice: "+ i);
            }
        }
    }
}