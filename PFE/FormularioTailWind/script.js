const nameInput = document.querySelector("#nome");
const emailInput = document.querySelector("#email");
const submitButton = document.querySelector("#submit-button");
const items = document.querySelector("#items");
const msg = document.querySelector("#mensagem")


submitButton.addEventListener("click", (e)=>{
    e.preventDefault();

    if(!emailInput.checkValidity()){
        showMessageError("Email inválido!");
        return
    }

    const nameValue = nameInput.value;
    const emailValue = emailInput.value;

    function showMessageError(message){
        msg.innerText=message;
        msg.classList="w-full  opacity-100 text-red-500 font-bold text-center transition-opacity duration-1000";

        setTimeout(()=>{
            msg.classList.replace("opacity-100","opacity-0")
        },2000)

        setTimeout(()=>{
            msg.innerText=""
        },3000)


        
       

    }

    if(!nameValue || !emailValue){
        showMessageError("Preencha todos os campos!");
        return
    }

    const li = document.createElement("li");
    li.innerText = `Nome: ${nameValue} - Email: ${emailValue}`;
    li.classList = "bg-white mt-2 p-2 shadow-md w-full rounded-lg text-center hover:transition ease-in-out duration-200 hover:scale-102 hover:border border-black"

    items.appendChild(li);

    nameInput.value="";
    emailInput.value="";
})
