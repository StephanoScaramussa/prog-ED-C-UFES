import java.util.*;

public class TestaColecoes{
    public static void main(String[] args){
        ArrayList<Integer> col2 = new ArrayList<>();
        ArrayList<Pessoa> pessoas = new ArrayList<>();

        pessoas.add(new Pessoa("Bruno", 19));
        pessoas.add(new Pessoa("Brunao", 21));
        pessoas.add(new Pessoa("Bruna", 18));

        System.out.println(pessoas);
        
        Collections.sort(pessoas); //nao e possivel ordenar referencias para objetos do tipo Pessoa
        
        //implementar uma interface Comparable para classe Pessoa
    }
}