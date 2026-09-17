class Alunos {

    constructor(nome, nota){
        this.nome = nome;
        this.nota = nota;
    }

    mostrarSituacao(){  
     console.log(`O aluno ${this.nome} está: ` + 
        (this.nota>=7 && "Aprovado" || "Reprovado"));
     return;
    }
}

const aluno1 = new Alunos("Jonas",7);

aluno1.mostrarSituacao();