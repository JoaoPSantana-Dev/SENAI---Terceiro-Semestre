const containers = document.querySelectorAll(".cards-container")

function addTask(){
    const input = document.getElementById("taskInput");
    const text = input.value.trim();

    console.log(text);

    if(text==="") return;

    const newCard = document.createElement("div");
    newCard.classList.add("card");
    newCard.draggable=true;
    newCard.innerText= text;

    newCard.addEventListener("dragstart", ()=> {
        newCard.classList.add("dragging");
    });

    newCard.addEventListener("dragend", ()=> {
        newCard.classList.remove("dragging");
    });

    document.getElementById("todo").appendChild(newCard);
    input.value = "";
}