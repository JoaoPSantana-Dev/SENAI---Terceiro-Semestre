const botao = document.getElementById("cadastrarProduto")
const vitrine = document.getElementById("vitrine")

botao.addEventListener("click", ()=>{
    const nomeProduto = document.getElementById("nomeProduto")
    const precoProduto = document.getElementById("precoProduto")
    const p = document.createElement("p")


    if(!nomeProduto.value || !precoProduto.value){
        nomeProduto.value = ""
        precoProduto.value = ""  
        alert("Preencha todos os campos")  
        return
    }

    const preco = Number(precoProduto.value);

    if(Number.isNaN((preco))){
        nomeProduto.value = ""
        precoProduto.value = ""  
        alert("O preco deve ser um número")  
        return
    }

    p.innerText=`Produto: ${nomeProduto.value} - R$ ${preco.toFixed(2)}`
    p.classList.add("card")

    vitrine.appendChild(p)

    nomeProduto.value = ""
    precoProduto.value = ""   
   
})