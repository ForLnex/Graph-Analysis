import java.util.List;

/*
 * A generic interface for representing graphs using adjacency lists that 
 * allows the user to utilize and create GraphAnalyzer objects.
 *
 * While equals() and toString() are both implemented by Object, both methods
 * should be overloaded to acquire the desired results.
 *
 * equals() should be overloaded to include a more meaningful equality test than the
 * default Object.equals().
 *
 * toString() should be overloaded to return a more meaningful identifier than the
 * default Object.equals().
 */
public interface Node{
	public boolean equals(Object other);
	public String toString();
	public List<Node> getAdjacent();
}
