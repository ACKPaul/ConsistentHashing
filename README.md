# ConsistentHashing
Consistent hashing is a technique used in distributed computing and storage systems to efficiently distribute and retrieve data across a changing set of nodes, while minimizing the number of keys that need to be remapped.

# Key Concepts in Consistent Hashing:
## Hash Function:

A hash function maps keys to a numeric space, typically a large integer. This numeric value determines where data or keys are stored.
## Ring Structure:

The hash values form a ring or circle (often visualized as a circle of integers). Each node in the system is mapped to one or more points on this ring using the hash function.
## Node Placement:

Each data item (or key) is mapped to a point on the ring using the same hash function. The next node clockwise on the ring from that point is responsible for storing the data.
## Node Additions and Removals:

When a node is added or removed from the system, only a fraction of the keys (typically those that map close to the node's position on the ring) need to be remapped, which makes the system scalable and efficient.
## Virtual Nodes (Replication):

To balance the load evenly among nodes, each physical node is typically represented by multiple virtual nodes or replicas on the ring. This technique helps to distribute the data more uniformly.
