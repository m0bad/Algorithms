function person_is_seller(name){
    return name[name.length -1] === 'm'
}

const graph={};

graph["you"] = ["alice", "bob", "claire"];
graph["bob"] = ["anuj", "peggy"];
graph["alice"] = ["peggy"];
graph["claire"] = ["thom", "jonny"];
graph["anuj"] = [];
graph["peggy"] = [];
graph["thom"] = [];
graph["jonny"] = [];

function search(name){
    let search_queue=[]
    search_queue=search_queue.concat(graph[name])
    const searched=[]//to keep track of who you previously searched
    while(search_queue.length){
        let person=search_queue.shift()
        if(searched.indexOf(person) === -1){
            if(person_is_seller(person)){
                console.log(person +" is a mango seller");
                return true;
            }
            search_queue=search_queue.concat(graph[person])
            searched.push(person)
        }
    }
    return false
}

search("you")
