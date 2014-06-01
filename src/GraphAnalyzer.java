import DataStructures.Node;
import DataStructures.DependencyData;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GraphAnalyzer{
	public final Node		ROOT;
	private List<String>	cyclesFound;
	private HashMap<Node, HashSet<Node>> dependencies;

	public GraphAnalyzer(Node root){
		this.ROOT = root;
	}

	public List<DependencyData> getDependencies(){
		if(dependencies == null)
			findDependencies();
		return dependencyList();	
	}

	private void findDependencies(){
		
	}
	
	private List<DependencyData> dependencyList(){
		List<DependencyData> dependencyList = new ArrayList<DependencyData>();

		return dependencyList;
	}


	public List<String> getCycles(){
		if (this.cyclesFound == null)
			findCycles();
		return this.cyclesFound;
	}

	private void findCycles(){
		Deque<Node> currentPath = new ArrayDeque<Node>();
		Set<Node> visited = new HashSet<Node>();
		cyclesFound = new ArrayList<String>();

		cyclesDFS(ROOT, currentPath, visited);
	}

	private void cyclesDFS(Node current, Deque<Node> currentPath, Set<Node> visited){
		currentPath.push(current);

		if (visited.contains(current)){
			cyclesFound.add(makeCycleString(currentPath));
			currentPath.pop();
			return;
		}else{
			visited.add(current);
			for (Node n : current.getChildren())
				cyclesDFS(n, currentPath, visited);
		}

		currentPath.pop();
		visited.remove(current);
	}

	private String makeCycleString(Deque<Node> path){
		StringBuilder cycleStringBuilder = new StringBuilder();

		for (Node n : path)
			cycleStringBuilder.append(" => " + n.toString());

		return cycleStringBuilder.toString();
	}
}
