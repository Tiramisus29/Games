const choices = ["rock", "paper", "scissors"];

function RPS(userChoice) {
    const end = document.getElementById("result");
    const myChoice = choices[Math.floor(Math.random() * 3)];
    const winner = whoWon(userChoice, myChoice);

    end.innerHTML = `You chose ${capitalize(userChoice)}<br>
    I chose ${capitalize(myChoice)}<br>
    ${winner}`;

}

function whoWon(user, me) {
    if (user == me)
        return "Looks like we got a draw! Let's play again!";

    if ((user == "rock" && me == "scissors") || 
       (user == "paper" && me == "rock") || 
       (user == "scissors" && me == "paper")) {
        return "Darn it! You win, Congratulations! ദ്ദി(˵ •̀ ᗜ - ˵ ) ✧";
       }
       
    else {
        return "I win! Better luck next time. (*˘︶˘*).｡*♡";
    }

}

function capitalize(word) {
    return word.charAt(0).toUpperCase() + word.slice(1);
}