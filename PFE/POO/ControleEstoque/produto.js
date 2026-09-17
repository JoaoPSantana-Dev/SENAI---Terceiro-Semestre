class Produto{

    constructor(nome,preco,quantidade){
        this.nome = nome;
        this.preco = preco;
        this.quantidade = quantidade;
    }

    atualizarPreco(novoPreco){
        if(novoPreco<=0){
            console.log("Por favor digite um preço maior que zero");
            return;
        }

        this.preco=novoPreco;
        console.log("Preço do produto atualizado com sucesso!");
        console.log(`O novo preço é: R$ ${(this.preco).toFixed(2)}`);
    }

    adicionarEstoque(quantidade){
        if(quantidade<=0){
            console.log("Por favor digite uma valor maior que zero");
            return;
        }    
            this.quantidade+=quantidade;
            console.log("Valor adicionado com sucesso");
            console.log(`A quantidade atual é: ${this.quantidade} `)
        }
    

    vender(quantidade){
        if(quantidade<=0){
            console.log("Por favor digite um valor maior que zero!!!");
            return;
        }

        if(quantidade>this.quantidade){
            console.log("Não é possível vender mais unidades do que a disponível no estoque!");
            return;
        }

        this.quantidade-=quantidade;
        console.log("Venda realizada com sucesso!");
        console.log(`O valor atual do estoque é: ${this.quantidade}`);
    }

    exibirInfo(){
        console.log(`O produto ${this.nome} custa R$ ${(this.preco).toFixed(2)} e restam ${this.quantidade}.`);
    }

}


    const produto1 = new Produto("Camiseta",50,10);

    produto1.exibirInfo();

    produto1.atualizarPreco(52);

    produto1.vender(10);
