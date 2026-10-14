const caixa = document.getElementById("caixa");
const area = document.getElementById("area");

caixa.addEventListener("dragstart",()=>{
    console.log("arrastando")
})

area.addEventListener("dragover",(e)=>{
    e.preventDefault()
    console.log("sobre area valida");
})

area.addEventListener("drop",()=>{
    console.log("elemento solto");
})