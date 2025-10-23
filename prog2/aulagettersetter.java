public class Aluno{
    private String nome;
    private double nota1, nota2;
    
    public Aluno(String nome, double nota1, double nota2){//construtor, se nao estiver declarado o proprio compilador o gera automaticamente e uma operacao
        //super();
        this.nome = nome;
        this.nota1 = nota1;
        this.nota2 = nota2;
    }

    public Aluno(){
        //polimorfismo
    }

    //metodos de acesso
    //getters e setters
    public String getNome(){ //getter e do tipo da variavel relacionada
        return nome;
    }
    public void setNome(String nome){ //parametro do setter e do tipo da string //variavel local(duplicada) sobrepoe a de instancia
        this.nome = nome;
    }
    public double getNota1(){
        return nota1;
    }
    public void setNota1(double nota1){
        if(nota1>=0.0 && nota1<=10.0){
            this.nota1 = nota1;
        } else{ //classes do modelo de dominio so vao guardar suas variaveis de instancias e apenas metodos simples
            System.out.printIn("A nota fornecida deve estar entre 0 e 10");
        }
    }
    public double getNota2(){
        return nota2;
    }
    public void setNota2(double nota2){
        this.nota2 = nota2;
    }
    public double calculaMedia(){
        return(nota1+nota2)/2;
    }
    //public void imprimeNome(){
    //    System.out.printIn(nome);  esse tipo de metodo nao deve ser feito por um objeto da classe aluno
    //}

    public static void main(String[] args){ //main temporaria para teste da classe aluno
        Aluno a1 = new Aluno();
        a1.setNome("Fulano");
        a1.setNota1(9.0);
        a1.setNota2(2.0);
        System.out.printIn("Nome:" + a1.getNome() + " Nota1:" + a1.getNota1() + " Nota2:" + a1.getNota2() + " Media:" + a1.calculaMedia());
        Aluno a2 = new Aluno("Ciclano", 2.0, 5.0);
    }
}

public static void main(String[] args){
    int[][] mat = new int[3][?];
    mat[0] = new int[2];
    mat[1] = new int[1];
    mat[2] = new int[4];

    for(int i = 0; i < mat.length; i++){
        for(int j = 0; j < mat[i].length; j++){
            System.out.printIn(mat[i][j] + " ");
        }
    }
}