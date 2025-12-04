import java.util.Comparator;

public class ComparaPessoaIdade implements Comparator<Pessoa>{


    @Override
    public int compareTo(Pessoa p1, Pessoa p2){
        int result = p1.getNome().compareTo(p2.getNome());

        if(result == 0){
            result = Integer.compare(p1.getIdade(), p2.getIdade());
        }

        return Integer.compare(p1.getIdade(), p2.getIdade());
    }
}