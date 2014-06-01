package DataStructures;

import java.util.List;

public interface Node{
	/**
	 * This method should be overloaded to utilize a more meaningful equality test than the default.
	 * 
	 * @return whether or not the two objects are to be considered equal.
	 */
	public boolean equals(Object other);

	/**
	 * Since you are overloading equals, you MUST overload hashCode() as well such that if two Objects are equal according to equals(), then calling hashCode() on each of the two objects must produce the same integet result
	 */
	public int hashCode();

	/**
	 * This method should be overloaded to return some meaningful identifier for a specific Node.
	 * 
	 * @return unique, meaningful identifier for given node.
	 */
	public String toString();

	/**
	 * Returns all of the Nodes reachable from this Node.
	 * 
	 * return all child Nodes.
	 */
	public List<Node> getChildren();
}
