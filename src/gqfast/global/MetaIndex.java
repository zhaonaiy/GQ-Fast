package gqfast.global;

import java.util.List;

public class MetaIndex {

	//private int indexID;
	private int gqFastIndexID;
	private int numColumns;
	private int indexMapByteSize;
	private List<Integer> columnEncodingsList;
	private List<Integer> columnEncodedByteSizesList;
	
	public MetaIndex(int gqFastIndexID, int numColumns, int indexMapByteSize,
			List<Integer> columnEncodingsList,
			List<Integer> columnEncodedByteSizesList) {
		//this.indexID = indexID;
		this.gqFastIndexID = gqFastIndexID;
		this.numColumns = numColumns;
		this.indexMapByteSize = indexMapByteSize;
		this.columnEncodingsList = columnEncodingsList;
		this.columnEncodedByteSizesList = columnEncodedByteSizesList;
	}

	
	public int getGQFastIndexID() {
		return gqFastIndexID;
	}

	public int getNumColumns() {
		return numColumns;
	}

	public int getIndexMapByteSize() {
		return indexMapByteSize;
	}

	public List<Integer> getColumnEncodingsList() {
		return columnEncodingsList;
	}

	public List<Integer> getColumnEncodedByteSizesList() {
		return columnEncodedByteSizesList;
	}	
}
