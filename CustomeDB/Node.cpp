#include "Node.h"

Node::Node() {
    client.setname("");
    client.setid(0);
    client.setphone("");
    client.setaddress("");
    client.setproject_id(0);
}

Node::Node(string name,int id,string phone,string address,int project_id) {
    client.setname(name);
    client.setid(id);
    client.setphone(phone);
    client.setaddress(address);
    client.setproject_id(project_id);
}

Client Node::getClient()
{
    return client;
}





                        