class GerenciamentoFinanceiro{

    constructor(receitas,despesas){
        if(!Array.isArray(receitas) || !Array.isArray(despesas)){
            console.log("Por favor, coloque arrays como valores para receitas e despesas!");
            return;
        }

       const receitasValidas = receitas.every(
            valor=>typeof valor ==="number" && !Number.isNaN(valor)
       );
       
       const despesasValidas = despesas.every(
        valor => typeof valor==="number" && !Number.isNaN(valor)
       );
    
       if(!receitasValidas || !despesasValidas){
        console.log("Todos os valores dentro dos Arrays precisam ser números");
        return;
       }

       const valoresReceitasPositivos = receitas.every(
        valor => valor>0
       );

       const valoresDespesasPositivos = despesas.every(
        valor => valor>0
       );

       if(!valoresReceitasPositivos || !valoresDespesasPositivos){
        console.log("Todos os valores nos arrays precisam ser positivos!")
        return;
       }

        this.receitas = receitas;
        this.despesas=despesas;
    }

    adicionarReceita(valor){
        if(typeof valor !=="number" || Number.isNaN(valor)){
            console.log("Por favo digite um número e não uma texto!")
            return;
        }

        if(valor<=0){
            console.log("Por favor digite um valor positivo!");
            return;
        }

        this.receitas.push(valor);
        console.log(`Valor de R$ ${valor.toFixed(2)} registrado com sucesso!`);
        return;
    }

    adicionarDespesa(valor){
        if(typeof valor !=="number" || Number.isNaN(valor)){
            console.log("Por favo digite um número e não uma texto!")
            return;
        }

        if(valor<=0){
            console.log("Por favor digite um valor positivo!");
            return;
        }

        this.despesas.push(valor);
        console.log(`Valor de R$ ${valor.toFixed(2)} registrado com sucesso!`);
        return;

    }


    calcularSaldo(){
       let saldo=0;
       let receitaTotal =0;
       let despesasTotal = 0;

       receitaTotal = this.receitas.reduce((soma,valor)=>soma+valor,0);
       despesasTotal = this.despesas.reduce((soma,valor)=>soma+valor,0);

       saldo=receitaTotal-despesasTotal;
       return saldo;
    }

    verificarSaudeFinanceira(){
        const saldo = this.calcularSaldo();
        let mensagem;

        if(saldo>0){
            mensagem="Sua situação é: No azul!";
        }
        else if(saldo==0){
            mensagem = "Sua situação: No limite!";
        }
        else{
            mensagem = "Sua situação: No vermelho!";
        } 

        console.log(`O seu saldo atual é: ${saldo}. `+mensagem);
    }
}



const receitas=[45]
const despesas=[10]

const joao = new GerenciamentoFinanceiro(receitas,despesas);

joao.adicionarReceita(25)
joao.adicionarDespesa(22)

joao.verificarSaudeFinanceira()

