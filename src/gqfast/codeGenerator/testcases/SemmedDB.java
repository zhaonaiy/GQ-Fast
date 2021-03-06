package gqfast.codeGenerator.testcases;

import java.util.ArrayList;
import java.util.List;

import gqfast.codeGenerator.AggregationOperator;
import gqfast.codeGenerator.CodeGenerator;
import gqfast.codeGenerator.JoinOperator;
import gqfast.codeGenerator.Operator;
import gqfast.codeGenerator.SelectionOperator;
import gqfast.codeGenerator.SemiJoinOperator;
import gqfast.codeGenerator.ThreadingOperator;
import gqfast.global.Alias;
import gqfast.global.MetaData;
import gqfast.global.MetaIndex;
import gqfast.global.MetaQuery;


public class SemmedDB {

	private static void initSemmedDBOperators(List<Operator> operators, MetaQuery query) {
			
		List<Integer> selections = new ArrayList<Integer>();
		selections.add(2019);
		Operator selection1 = new SelectionOperator(selections, query.getAliases().get(0));
		operators.add(selection1);
		
	
		List<Integer> column1IDs = new ArrayList<Integer>();
		column1IDs.add(0);
		
		//public JoinOperator(boolean entityFlag, List<Integer> columnIDs,  Alias alias,  Alias drivingAlias, int drivingAliasColumn) {
		Operator join1 = new JoinOperator(false, column1IDs, query.getAliases().get(1), query.getAliases().get(0), 0);
		
		operators.add(join1);
		
	
		List<Integer> column2IDs = new ArrayList<Integer>();
		column2IDs.add(0);
		
		Operator join2 = new JoinOperator(false, column2IDs, query.getAliases().get(2), query.getAliases().get(1), 0);
		
		operators.add(join2);
		
		
		List<Integer> column3IDs = new ArrayList<Integer>();
		column3IDs.add(0);
		
		Operator join3 = new JoinOperator(false, column3IDs, query.getAliases().get(3), query.getAliases().get(2), 0);
		
		operators.add(join3);
		
		List<Integer> column4IDs = new ArrayList<Integer>();
		column4IDs.add(0);
		
		Operator semijoin4 = new SemiJoinOperator(false, column4IDs, query.getAliases().get(4), query.getAliases().get(3), 0);
		
		operators.add(semijoin4);
		
		List<Integer> column5IDs = new ArrayList<Integer>();
		column5IDs.add(0);
		
		Operator join5 = new JoinOperator(false, column5IDs, query.getAliases().get(5), query.getAliases().get(4), 0);
		
		operators.add(join5);
		
		List<Integer> column6IDs = new ArrayList<Integer>();
		column6IDs.add(0);
		
		Operator join6 = new JoinOperator(false, column6IDs, query.getAliases().get(6), query.getAliases().get(5), 0);
		
		operators.add(join6);
		
		int gqFastIndexID = 5;
		
		String aggString = "1";
		
		List<Alias> aggAliasList = new ArrayList<Alias>();
		
		List<Integer> aggOpColList = new ArrayList<Integer>();

		/*public AggregationOperator(int gqFastIndexID, 
				int dataType, String aggregationString, 
				List<Alias> aggregationVariablesAliases, List<Integer> aggregationVariablesColumns, Alias drivingAlias, 
				int drivingAliasColumn) {*/
		
		
		Operator agg = new AggregationOperator(gqFastIndexID, 
				AggregationOperator.AGGREGATION_INT, aggString, aggAliasList, aggOpColList, query.getAliases().get(6), 0);
	
		operators.add(agg);
		
	}

	private static void initSemmedDBOperatorsThreaded(List<Operator> operators, MetaQuery query) {
		
		List<Integer> selections = new ArrayList<Integer>();
		selections.add(2019);
		Operator selection1 = new SelectionOperator(selections, query.getAliases().get(0));
		operators.add(selection1);
		
	
		List<Integer> column1IDs = new ArrayList<Integer>();
		column1IDs.add(0);
		
		//public JoinOperator(boolean entityFlag, List<Integer> columnIDs,  Alias alias,  Alias drivingAlias, int drivingAliasColumn) {
		Operator join1 = new JoinOperator(false, column1IDs, query.getAliases().get(1), query.getAliases().get(0), 0);
		
		operators.add(join1);
		
		Operator threadingOp = new ThreadingOperator(query.getAliases().get(1), false);
		operators.add(threadingOp);
		
		List<Integer> column2IDs = new ArrayList<Integer>();
		column2IDs.add(0);
		
		Operator join2 = new JoinOperator(false, column2IDs, query.getAliases().get(2), query.getAliases().get(1), 0);
		
		operators.add(join2);
		
		
		List<Integer> column3IDs = new ArrayList<Integer>();
		column3IDs.add(0);
		
		Operator join3 = new JoinOperator(false, column3IDs, query.getAliases().get(3), query.getAliases().get(2), 0);
		
		operators.add(join3);
		
		List<Integer> column4IDs = new ArrayList<Integer>();
		column4IDs.add(0);
		
		Operator semijoin4 = new SemiJoinOperator(false, column4IDs, query.getAliases().get(4), query.getAliases().get(3), 0);
		
		operators.add(semijoin4);
		
		List<Integer> column5IDs = new ArrayList<Integer>();
		column5IDs.add(0);
		
		Operator join5 = new JoinOperator(false, column5IDs, query.getAliases().get(5), query.getAliases().get(4), 0);
		
		operators.add(join5);
		
		List<Integer> column6IDs = new ArrayList<Integer>();
		column6IDs.add(0);
		
		Operator join6 = new JoinOperator(false, column6IDs, query.getAliases().get(6), query.getAliases().get(5), 0);
		
		operators.add(join6);
		
		int gqFastIndexID = 5;
		
		String aggString = "1";
		
		List<Alias> aggAliasList = new ArrayList<Alias>();
		
		List<Integer> aggOpColList = new ArrayList<Integer>();

		/*public AggregationOperator(int gqFastIndexID, 
				int dataType, String aggregationString, 
				List<Alias> aggregationVariablesAliases, List<Integer> aggregationVariablesColumns, Alias drivingAlias, 
				int drivingAliasColumn) {*/
		
		
		Operator agg = new AggregationOperator(gqFastIndexID, 
				AggregationOperator.AGGREGATION_INT, aggString, aggAliasList, aggOpColList, query.getAliases().get(6), 0);
	
		operators.add(agg);
		
	}

	private static void initSemmedDBQueries(MetaData metadata, String queryName, int numThreads) {

		List<Alias> aliases = new ArrayList<Alias>();
		
		Alias alias0 = new Alias(0, "concept1");
		Alias alias1 = new Alias(1, "concept_semtype1", metadata.getIndexList().get(0));
		Alias alias2 = new Alias(2, "predication1", metadata.getIndexList().get(1));
		Alias alias3 = new Alias(3, "sentence1", metadata.getIndexList().get(2));
		Alias alias4 = new Alias(4, "predication2", metadata.getIndexList().get(3));
		Alias alias5 = new Alias(5, "concept_semtype2", metadata.getIndexList().get(4));
		Alias alias6 = new Alias(6, "concept2", metadata.getIndexList().get(5));
			
		aliases.add(alias0);
		aliases.add(alias1);
		aliases.add(alias2);
		aliases.add(alias3);
		aliases.add(alias4);
		aliases.add(alias5);
		aliases.add(alias6);
		
		MetaQuery smdbOptimal = new MetaQuery(1, queryName, numThreads, aliases);
		
		metadata.getQueryList().add(smdbOptimal);	
		metadata.setCurrentQueryID(metadata.getQueryList().size()-1);
	}


	private static void initSemmedDBIndexes(MetaData metadata) {
		// CS1
		int indexID = 0;
		int numColumns = 1;
		List<Integer> columnEncodingsList0 = new ArrayList<Integer>();
		columnEncodingsList0.add(MetaData.ENCODING_BB);
		List<Integer> columnEncodedByteSizesList0 = new ArrayList<Integer>();
		columnEncodedByteSizesList0.add(MetaData.BYTES_4);
		
		MetaIndex CS1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList0, columnEncodedByteSizesList0);
		metadata.getIndexList().put(indexID, CS1);
		
		// PA1
		indexID = 1;
		numColumns = 1;
		List<Integer> columnEncodingsList1 = new ArrayList<Integer>();
		columnEncodingsList1.add(MetaData.ENCODING_BB);
		List<Integer> columnEncodedByteSizesList1 = new ArrayList<Integer>();
		columnEncodedByteSizesList1.add(MetaData.BYTES_4);
		
		MetaIndex PA1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList1, columnEncodedByteSizesList1);
		metadata.getIndexList().put(indexID, PA1);

		// SP1
		indexID = 2;
		numColumns = 1;
		List<Integer> columnEncodingsList2 = new ArrayList<Integer>();
		columnEncodingsList2.add(MetaData.ENCODING_BB);	
		List<Integer >columnEncodedByteSizesList2 = new ArrayList<Integer>();
		columnEncodedByteSizesList2.add(MetaData.BYTES_4);
		MetaIndex SP1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList2, columnEncodedByteSizesList2);
		metadata.getIndexList().put(indexID, SP1);
		
		// SP2
		indexID = 3;
		numColumns = 1;
		List<Integer> columnEncodingsList3 = new ArrayList<Integer>();
		columnEncodingsList3.add(MetaData.ENCODING_BB);
		
		List<Integer >columnEncodedByteSizesList3 = new ArrayList<Integer>();
		columnEncodedByteSizesList3.add(MetaData.BYTES_4);
		
		MetaIndex SP2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList3, columnEncodedByteSizesList3);
		metadata.getIndexList().put(indexID, SP2);
		
		// PA2
		indexID = 4;
		numColumns = 1;
		List<Integer> columnEncodingsList4 = new ArrayList<Integer>();
		columnEncodingsList4.add(MetaData.ENCODING_HUFFMAN);
		List<Integer> columnEncodedByteSizesList4 = new ArrayList<Integer>();
		columnEncodedByteSizesList4.add(MetaData.BYTES_4);
		
		MetaIndex PA2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList4, columnEncodedByteSizesList4);
		metadata.getIndexList().put(indexID, PA2);

		// CS2
		indexID = 5;
		numColumns = 1;
		List<Integer> columnEncodingsList5 = new ArrayList<Integer>();
		columnEncodingsList5.add(MetaData.ENCODING_BB);
		List<Integer> columnEncodedByteSizesList5 = new ArrayList<Integer>();
		columnEncodedByteSizesList5.add(MetaData.BYTES_4);
		
		MetaIndex CS2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList5, columnEncodedByteSizesList5);
		metadata.getIndexList().put(indexID, CS2);
		
	}
	
	private static void initSemmedDBIndexes(MetaData metadata, int encoding) {
		// CS1
		int indexID = 0;
		int numColumns = 1;
		List<Integer> columnEncodingsList0 = new ArrayList<Integer>();
		columnEncodingsList0.add(encoding);
		List<Integer> columnEncodedByteSizesList0 = new ArrayList<Integer>();
		columnEncodedByteSizesList0.add(MetaData.BYTES_4);
		
		
		/*public MetaIndex(int indexID, int gqFastIndexID, int numColumns, int indexMapByteSize,
				List<Integer> columnEncodingsList,
				List<Integer> columnEncodedByteSizesList) {*/
		
		MetaIndex CS1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList0, columnEncodedByteSizesList0);
		metadata.getIndexList().put(indexID, CS1);

		// PA1
		indexID = 1;
		numColumns = 1;
		List<Integer> columnEncodingsList1 = new ArrayList<Integer>();
		columnEncodingsList1.add(encoding);
		List<Integer> columnEncodedByteSizesList1 = new ArrayList<Integer>();
		columnEncodedByteSizesList1.add(MetaData.BYTES_4);
		
		MetaIndex PA1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList1, columnEncodedByteSizesList1);
		metadata.getIndexList().put(indexID, PA1);

		// SP1
		indexID = 2;
		numColumns = 1;
		List<Integer> columnEncodingsList2 = new ArrayList<Integer>();
		columnEncodingsList2.add(encoding);	
		List<Integer >columnEncodedByteSizesList2 = new ArrayList<Integer>();
		columnEncodedByteSizesList2.add(MetaData.BYTES_4);
		MetaIndex SP1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList2, columnEncodedByteSizesList2);
		metadata.getIndexList().put(indexID, SP1);
		
		// SP2
		indexID = 3;
		numColumns = 1;
		List<Integer> columnEncodingsList3 = new ArrayList<Integer>();
		columnEncodingsList3.add(encoding);
		
		List<Integer >columnEncodedByteSizesList3 = new ArrayList<Integer>();
		columnEncodedByteSizesList3.add(MetaData.BYTES_4);
		
		MetaIndex SP2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList3, columnEncodedByteSizesList3);
		metadata.getIndexList().put(indexID, SP2);
		
		// PA2
		indexID = 4;
		numColumns = 1;
		List<Integer> columnEncodingsList4 = new ArrayList<Integer>();
		columnEncodingsList4.add(encoding);
		List<Integer> columnEncodedByteSizesList4 = new ArrayList<Integer>();
		columnEncodedByteSizesList4.add(MetaData.BYTES_4);
		
		MetaIndex PA2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList4, columnEncodedByteSizesList4);
		metadata.getIndexList().put(indexID, PA2);

		// CS2
		indexID = 5;
		numColumns = 1;
		List<Integer> columnEncodingsList5 = new ArrayList<Integer>();
		columnEncodingsList5.add(encoding);
		List<Integer> columnEncodedByteSizesList5 = new ArrayList<Integer>();
		columnEncodedByteSizesList5.add(MetaData.BYTES_4);
		
		MetaIndex CS2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, columnEncodingsList5, columnEncodedByteSizesList5);
		metadata.getIndexList().put(indexID, CS2);
		
	}

	private static void runQuery(String queryName, int numThreads, int encoding) {
		List<Operator> operators = new ArrayList<Operator>();
		MetaData metadata = new MetaData();
		
		initSemmedDBIndexes(metadata, encoding);
		initSemmedDBQueries(metadata, queryName, numThreads);
		MetaQuery query = metadata.getQueryList().get(metadata.getCurrentQueryID());
		if (numThreads > 1) {
			initSemmedDBOperatorsThreaded(operators, query);
		}
		else {
			initSemmedDBOperators(operators, query);
		}
		CodeGenerator.generateCode(operators, metadata);
	}
	
	private static void runQuery(String queryName, int numThreads, boolean b) {
		List<Operator> operators = new ArrayList<Operator>();
		MetaData metadata = new MetaData();
		initSemmedDBIndexes(metadata);
		initSemmedDBQueries(metadata, queryName, numThreads);
		MetaQuery query = metadata.getQueryList().get(metadata.getCurrentQueryID());
		if (numThreads > 1) {
			initSemmedDBOperatorsThreaded(operators, query);
		}
		else {
			initSemmedDBOperators(operators, query);
		}
		CodeGenerator.generateCode(operators, metadata);
	}
	
	public static void main(String[] args) {
				
		// SemmedDB Atropine Query
		
		//Optimal
		runQuery("smdb_optimal_0threads", 1, true);
		runQuery("smdb_optimal_1threads", 10, true);
		runQuery("smdb_optimal_2threads", 2, true);
		runQuery("smdb_optimal_4threads", 4, true);
		
		//Huffman
		runQuery("smdb_huffman_0threads", 1, MetaData.ENCODING_HUFFMAN);
		runQuery("smdb_huffman_1threads", 10, MetaData.ENCODING_HUFFMAN);
		runQuery("smdb_huffman_2threads", 2, MetaData.ENCODING_HUFFMAN);
		runQuery("smdb_huffman_4threads", 4, MetaData.ENCODING_HUFFMAN);
		
		//BCA
		runQuery("smdb_bca_0threads", 1, MetaData.ENCODING_BCA);
		runQuery("smdb_bca_1threads", 10, MetaData.ENCODING_BCA);
		runQuery("smdb_bca_2threads", 2, MetaData.ENCODING_BCA);
		runQuery("smdb_bca_4threads", 4, MetaData.ENCODING_BCA);
		
		//Array
		runQuery("smdb_array_0threads", 1, MetaData.ENCODING_UA);
		runQuery("smdb_array_1threads", 10, MetaData.ENCODING_UA);
		runQuery("smdb_array_2threads", 2, MetaData.ENCODING_UA);
		runQuery("smdb_array_4threads", 4, MetaData.ENCODING_UA);
	
		//BB
		runQuery("smdb_bb_0threads", 1, MetaData.ENCODING_BB);
		runQuery("smdb_bb_1threads", 10, MetaData.ENCODING_BB);
		runQuery("smdb_bb_2threads", 2, MetaData.ENCODING_BB);
		runQuery("smdb_bb_4threads", 4, MetaData.ENCODING_BB);	
		
		
	}
	

	
}
