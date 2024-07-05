#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "MurmurHash3.h" // Ensure you have the MurmurHash3 implementation

/* author : Achintya Kumar Paul
 *  Email  : kumarpaul51@gmail.com
 */

using namespace std;

class ConsistentHashing {
    // Map to store the hash values and their corresponding nodes
    map<int, string> nodes;

    // Number of virtual nodes (replicas) per actual node
    int replicas;

public:
    ConsistentHashing(int replicas) : replicas(replicas) {}

    // Add a node with its replicas to the hash ring
    void addNode(string node) {
        for (int i = 0; i < replicas; i++) {
            string virtualNode = node + "##" + to_string(i);
            int hash = hashFunction(virtualNode);
            if (nodes.find(hash) == nodes.end()) {
                nodes[hash] = node;
            }
            else {
                cout << "Virtual node already exists: " << virtualNode << " (Hash: " << hash << ")" << endl;
            }
        }
    }

    // Remove a node and its replicas from the hash ring
    void removeNode(string node) {
        for (int i = 0; i < replicas; i++) {
            string virtualNode = node + "##" + to_string(i);
            int hash = hashFunction(virtualNode);
            nodes.erase(hash);
        }
    }

    // Get the node responsible for the given key
    string getNode(string key) {
        if (nodes.empty()) return {};

        int hash = hashFunction(key);
        // Binary search to get the first node whose hash is greater than or equal to the key's hash
        auto it = nodes.lower_bound(hash);

        if (it == nodes.end()) {
            it = nodes.begin();
        }

        return it->second;
    }

    // Print the hash distribution (for testing purposes)
    void printHashDistribution() {
        for (auto& node : nodes) {
            cout << "Key: " << node.first << " and Node is " << node.second << endl;
        }
    }

    // Find the nodes that would be affected if a new node is added
    vector<string> findAffectedNodes(string newNode) {
        vector<string> affectedNodes;
        for (int i = 0; i < replicas; i++) {
            string virtualNode = newNode + "##" + to_string(i);
            affectedNodes.push_back(getNode(virtualNode));
        }
        return affectedNodes;
    }

private:
    // Hash function using MurmurHash3
    uint32_t hashFunction(string nodeKey) {
        uint32_t hashValue[1];
        MurmurHash3_x86_32(nodeKey.c_str(), (int)nodeKey.length(), 0, hashValue);
        return hashValue[0];
    }
};

