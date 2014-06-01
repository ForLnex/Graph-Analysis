public interface DependencyData{
	public Node getParentNode();

	public List<Node> getDependencies();

	public boolean addDependency(Node dependency);
}
