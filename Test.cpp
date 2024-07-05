#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "ConsistentHashing.h"

using namespace std;

int main() {
    ConsistentHashing ch(3); // Number of replicas per node (virtual nodes)

    // Add nodes to the hash ring
    ch.addNode("Node1");
    ch.addNode("Node2");
    ch.addNode("Node3");
    ch.addNode("Node4");
    ch.addNode("Node5");
    ch.addNode("Node6");
    ch.addNode("Node7");
    ch.addNode("Node8");

    // Print the initial hash distribution
    cout << "Initial hash distribution:" << endl;
    ch.printHashDistribution();

    // Test key-to-node mapping
    vector<string> keys = { "Key1", "Key2", "Key3", "Key4", "Key5", "Achintya", "Server1" };
    cout << "Key to node mapping:" << endl;
    for (const auto& key : keys) {
        cout << "Key: " << key << " is mapped to " << ch.getNode(key) << endl;
    }

    // Find nodes affected by adding a new node
    auto affectedNodes = ch.findAffectedNodes("Node9");
    cout << "Nodes affected by adding Node9:" << endl;
    for (auto node : affectedNodes) {
        cout << node << " ";
    }
    cout << endl;

    // Add a new node to the hash ring
    ch.addNode("Node9");

    // Print the updated hash distribution
    cout << "Updated hash distribution after adding Node9:" << endl;
    ch.printHashDistribution();

    cout << "#####################################" << endl;

    // Test key-to-node mapping again after adding the new node
    cout << "Key to node mapping after adding Node9:" << endl;
    for (const auto& key : keys) {
        cout << key << " is mapped to " << ch.getNode(key) << endl;
    }

    // Attempt to add Node8 again
    ch.addNode("Node8");

    return 0;
}
