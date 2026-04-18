class Node {
    constructor(song) {
        this.song = song;
        this.next = null;
        this.prev = null;
    }
}

let head = null;
let current = null;

function addSong() {
    const input = document.getElementById("songInput");
    const songName = input.value.trim();
    if (!songName) return;

    const newNode = new Node(songName);

    if (!head) {
        head = newNode;
        head.next = head;
        head.prev = head;
        current = head;
    } else {
        const last = head.prev;

        last.next = newNode;
        newNode.prev = last;
        newNode.next = head;
        head.prev = newNode;
    }

    input.value = "";
    render();
}

function deleteSong() {
    if (!current) return;

    if (current.next === current) {
        head = null;
        current = null;
    } else {
        current.prev.next = current.next;
        current.next.prev = current.prev;

        if (current === head) head = current.next;
        current = current.next;
    }

    render();
}

function playNext() {
    if (current) {
        current = current.next;
        render();
    }
}

function playPrev() {
    if (current) {
        current = current.prev;
        render();
    }
}

function playSong(node) {
    current = node;
    render();
}

function render() {
    const list = document.getElementById("playlist");
    const now = document.getElementById("nowPlaying");

    list.innerHTML = "";

    if (!head) {
        now.innerText = "None";
        return;
    }

    let temp = head;

    do {
        const li = document.createElement("li");
        li.innerText = temp.song;

        if (temp === current) {
            li.classList.add("active");
        }

        li.onclick = () => playSong(temp);

        list.appendChild(li);
        temp = temp.next;

    } while (temp !== head);

    now.innerText = current.song;
}