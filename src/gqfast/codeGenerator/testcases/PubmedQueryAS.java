package gqfast.codeGenerator.testcases;

import java.util.ArrayList;
import java.util.List;

import gqfast.codeGenerator.AggregationOperator;
import gqfast.codeGenerator.CodeGenerator;
import gqfast.codeGenerator.JoinOperator;
import gqfast.codeGenerator.Operator;
import gqfast.codeGenerator.SelectionOperator;
import gqfast.codeGenerator.ThreadingOperator;
import gqfast.global.Alias;
import gqfast.global.MetaData;
import gqfast.global.MetaIndex;
import gqfast.global.MetaQuery;


public class PubmedQueryAS {


	private static void initQ5Queries(MetaData metadata, String queryName, int numThreads) {

		List<Alias> aliases = new ArrayList<Alias>();
		
		Alias alias0 = new Alias(0, "author1");
		Alias alias1 = new Alias(1, "doc1", metadata.getIndexMap().get(0));
		Alias alias2 = new Alias(2, "term", metadata.getIndexMap().get(2));
		Alias alias3 = new Alias(3, "doc2", metadata.getIndexMap().get(3));
		Alias alias4 = new Alias(4, "author2", metadata.getIndexMap().get(4));
		Alias alias5 = new Alias(5, "year", metadata.getIndexMap().get(1));
		
		aliases.add(alias0);
		aliases.add(alias1);
		aliases.add(alias2);
		aliases.add(alias3);
		aliases.add(alias4);
		aliases.add(alias5);
		
		// public MetaQuery(int queryID, String queryName, int numThreads,
		// int numBuffers, int bufferPoolSize, List<String> aliases)
		MetaQuery q5Optimal = new MetaQuery(0, queryName, numThreads, aliases);
			
		metadata.getQueryList().add(q5Optimal);
		metadata.setCurrentQueryID(metadata.getQueryList().size()-1);
		
	}
	


	private static void initQ5Indexes(MetaData metadata, int encodingType) {
		
		// DA1
		int indexID = 0;
		int numColumns = 1;
		List<Integer> columnEncodingsList0 = new ArrayList<Integer>();
		columnEncodingsList0.add(encodingType);
		List<Integer> columnEncodedByteSizesList0 = new ArrayList<Integer>();
		columnEncodedByteSizesList0.add(MetaData.BYTES_4);
		
		long indexDomainDummy = 1000;
		List<Long> colDomainsDummy = new ArrayList<Long>();
		
		MetaIndex DA1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList0, columnEncodedByteSizesList0, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DA1);
		
		// DY
		indexID = 1;
		numColumns = 1;
		List<Integer> columnEncodingsList1 = new ArrayList<Integer>();
		columnEncodingsList1.add(encodingType);
		List<Integer> columnEncodedByteSizesList1 = new ArrayList<Integer>();
		columnEncodedByteSizesList1.add(MetaData.BYTES_4);
		
		MetaIndex DY = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList1, columnEncodedByteSizesList1, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DY);

		// DT1
		indexID = 2;
		numColumns = 2;
		List<Integer> columnEncodingsList2 = new ArrayList<Integer>();
		columnEncodingsList2.add(encodingType);
		columnEncodingsList2.add(encodingType);
		
		List<Integer >columnEncodedByteSizesList2 = new ArrayList<Integer>();
		columnEncodedByteSizesList2.add(MetaData.BYTES_4);
		columnEncodedByteSizesList2.add(MetaData.BYTES_1);
		
		MetaIndex DT1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList2, columnEncodedByteSizesList2, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DT1);
		
		// DT2
		indexID = 3;
		numColumns = 2;
		List<Integer> columnEncodingsList3 = new ArrayList<Integer>();
		columnEncodingsList3.add(encodingType);
		columnEncodingsList3.add(encodingType);
		
		List<Integer >columnEncodedByteSizesList3 = new ArrayList<Integer>();
		columnEncodedByteSizesList3.add(MetaData.BYTES_4);
		columnEncodedByteSizesList3.add(MetaData.BYTES_1);
		
		MetaIndex DT2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList3, columnEncodedByteSizesList3, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DT2);
		
		// DA2
		indexID = 4;
		numColumns = 1;
		List<Integer> columnEncodingsList4 = new ArrayList<Integer>();
		columnEncodingsList4.add(encodingType);
		List<Integer> columnEncodedByteSizesList4 = new ArrayList<Integer>();
		columnEncodedByteSizesList4.add(MetaData.BYTES_4);
		
		MetaIndex DA2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList4, columnEncodedByteSizesList4, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DA2);

	}
	private static void initQ5Indexes(MetaData metadata) {
				
		// DA1
		int indexID = 0;
		int numColumns = 1;
		List<Integer> columnEncodingsList0 = new ArrayList<Integer>();
		columnEncodingsList0.add(MetaData.ENCODING_BB);
		List<Integer> columnEncodedByteSizesList0 = new ArrayList<Integer>();
		columnEncodedByteSizesList0.add(MetaData.BYTES_4);
		
		long indexDomainDummy = 1000;
		List<Long> colDomainsDummy = new ArrayList<Long>();
		
		MetaIndex DA1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList0, columnEncodedByteSizesList0, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DA1);

		// DY
		indexID = 1;
		numColumns = 1;
		List<Integer> columnEncodingsList1 = new ArrayList<Integer>();
		columnEncodingsList1.add(MetaData.ENCODING_BCA);
		List<Integer> columnEncodedByteSizesList1 = new ArrayList<Integer>();
		columnEncodedByteSizesList1.add(MetaData.BYTES_4);
		
		MetaIndex DY = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList1, columnEncodedByteSizesList1, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DY);

		// DT1
		indexID = 2;
		numColumns = 2;
		List<Integer> columnEncodingsList2 = new ArrayList<Integer>();
		columnEncodingsList2.add(MetaData.ENCODING_BB);
		columnEncodingsList2.add(MetaData.ENCODING_HUFFMAN);
		
		List<Integer >columnEncodedByteSizesList2 = new ArrayList<Integer>();
		columnEncodedByteSizesList2.add(MetaData.BYTES_4);
		columnEncodedByteSizesList2.add(MetaData.BYTES_1);
		
		MetaIndex DT1 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList2, columnEncodedByteSizesList2, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DT1);
		
		// DT2
		indexID = 3;
		numColumns = 2;
		List<Integer> columnEncodingsList3 = new ArrayList<Integer>();
		columnEncodingsList3.add(MetaData.ENCODING_BB);
		columnEncodingsList3.add(MetaData.ENCODING_HUFFMAN);
		
		List<Integer >columnEncodedByteSizesList3 = new ArrayList<Integer>();
		columnEncodedByteSizesList3.add(MetaData.BYTES_4);
		columnEncodedByteSizesList3.add(MetaData.BYTES_1);
		
		MetaIndex DT2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList3, columnEncodedByteSizesList3, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DT2);
		
		// DA2
		indexID = 4;
		numColumns = 1;
		List<Integer> columnEncodingsList4 = new ArrayList<Integer>();
		columnEncodingsList4.add(MetaData.ENCODING_BCA);
		List<Integer> columnEncodedByteSizesList4 = new ArrayList<Integer>();
		columnEncodedByteSizesList4.add(MetaData.BYTES_4);
		
		MetaIndex DA2 = new MetaIndex(indexID, numColumns, MetaData.BYTES_4, indexDomainDummy, columnEncodingsList4, columnEncodedByteSizesList4, colDomainsDummy);
		metadata.getIndexMap().put(indexID, DA2);

	}
	
	


	


	
	private static void initQ5OperatorsThreaded(List<Operator> operators, MetaQuery query, List<Integer> selections) {
	
		List<Alias> aliases = query.getAliases();
		Operator selection1 = new SelectionOperator(selections, aliases.get(0));
		operators.add(selection1);
		
		List<Integer> column1IDs = new ArrayList<Integer>();
		column1IDs.add(0);
		
		// JoinOperator(boolean entityFlag, List<Integer> columnIDs,  Alias alias, int loopColumn, Alias drivingAlias, int drivingAliasColumn) {
		Operator join1 = new JoinOperator(false, column1IDs, aliases.get(1), aliases.get(0), 0);	
		operators.add(join1);
		
		List<Integer> column2IDs = new ArrayList<Integer>();
		column2IDs.add(0);
		column2IDs.add(1);
		Operator join2 = new JoinOperator(false, column2IDs, aliases.get(2), aliases.get(1), 0);
		
		operators.add(join2);
		
		Operator threadOp = new ThreadingOperator(aliases.get(2), false);
		operators.add(threadOp);
		
		
		List<Integer> column3IDs = new ArrayList<Integer>();
		column3IDs.add(0);
		column3IDs.add(1);
		Operator join3 = new JoinOperator(false, column3IDs, aliases.get(3), aliases.get(2), 0);
		
		operators.add(join3);
		
		List<Integer> column4IDs = new ArrayList<Integer>();
		column4IDs.add(0);
		Operator join4 = new JoinOperator(true, column4IDs, aliases.get(5), aliases.get(3), 0);
		
		operators.add(join4);
		
		List<Integer> column5IDs = new ArrayList<Integer>();
		column5IDs.add(0);
		Operator join5 = new JoinOperator(false, column5IDs, aliases.get(4), aliases.get(3), 0);
		operators.add(join5);
		
		int aggregationindexID = 4;
		
		String aggString = "(double)( op0 * op1 )/(2017 - op2 )";
		
		List<Alias> aggAliasList = new ArrayList<Alias>();
		aggAliasList.add(query.getAliases().get(2));
		aggAliasList.add(query.getAliases().get(3));
		aggAliasList.add(query.getAliases().get(5));
		
		List<Integer> aggOpColList = new ArrayList<Integer>();
		aggOpColList.add(1);
		aggOpColList.add(1);
		aggOpColList.add(0);

		Operator agg = new AggregationOperator(aggregationindexID, 
				AggregationOperator.AGGREGATION_DOUBLE, aggString, aggAliasList, aggOpColList, aliases.get(4), 0);
	
		operators.add(agg);
	}

	private static void initQ5Operators(List<Operator> operators, MetaQuery query, List<Integer> selections) {
		List<Alias> aliases = query.getAliases();
		
		// Alias alias0 = new Alias(0, "author1");
		// Alias alias1 = new Alias(1, "doc1", metadata.getIndexMap().get(0));
		// Alias alias5 = new Alias(5, "year", metadata.getIndexMap().get(1));
		// Alias alias2 = new Alias(2, "term", metadata.getIndexMap().get(2));
		// Alias alias3 = new Alias(3, "doc2", metadata.getIndexMap().get(3));
		// Alias alias4 = new Alias(4, "author2", metadata.getIndexMap().get(4));
		

		Operator selection1 = new SelectionOperator(selections, aliases.get(0));
		operators.add(selection1);
		
		List<Integer> column1IDs = new ArrayList<Integer>();
		column1IDs.add(0);
		
		//JoinOperator(boolean entityFlag, List<Integer> columnIDs,  Alias alias, Alias drivingAlias, int drivingAliasColumn) 
		Operator join1 = new JoinOperator(false, column1IDs, aliases.get(1), aliases.get(0), 0);	
		operators.add(join1);
		
		List<Integer> column2IDs = new ArrayList<Integer>();
		column2IDs.add(0);
		column2IDs.add(1);
		Operator join2 = new JoinOperator(false, column2IDs, aliases.get(2), aliases.get(1), 0);
		
		operators.add(join2);
				
		List<Integer> column3IDs = new ArrayList<Integer>();
		column3IDs.add(0);
		column3IDs.add(1);
		Operator join3 = new JoinOperator(false, column3IDs, aliases.get(3), aliases.get(2), 0);
		
		operators.add(join3);
		
		List<Integer> column4IDs = new ArrayList<Integer>();
		column4IDs.add(0);
		Operator join4 = new JoinOperator(true, column4IDs, aliases.get(5), aliases.get(3), 0);
		
		operators.add(join4);
		
		List<Integer> column5IDs = new ArrayList<Integer>();
		column5IDs.add(0);
		Operator join5 = new JoinOperator(false, column5IDs, aliases.get(4), aliases.get(3), 0);
		operators.add(join5);
		
		int aggregationindexID = 4;
		
		String aggString = "(double)( op0 * op1 )/(2017 - op2 )";
		
		List<Alias> aggAliasList = new ArrayList<Alias>();
		aggAliasList.add(query.getAliases().get(2));
		aggAliasList.add(query.getAliases().get(3));
		aggAliasList.add(query.getAliases().get(5));
		
		List<Integer> aggOpColList = new ArrayList<Integer>();
		aggOpColList.add(1);
		aggOpColList.add(1);
		aggOpColList.add(0);

		Operator agg = new AggregationOperator(aggregationindexID, 
				AggregationOperator.AGGREGATION_DOUBLE, aggString, aggAliasList, aggOpColList, aliases.get(4), 0);
	
		operators.add(agg);
	}


	

	private static void runQ5(String queryName, int numThreads, List<Integer> selections, int encoding) {
		List<Operator> operators = new ArrayList<Operator>();
		MetaData metadata = new MetaData();
		initQ5Indexes(metadata, encoding);
		initQ5Queries(metadata, queryName, numThreads);
		MetaQuery query = metadata.getQueryList().get(metadata.getCurrentQueryID());
		if (numThreads > 1) {
			initQ5OperatorsThreaded(operators, query, selections);
		}
		else {
			initQ5Operators(operators, query, selections);
		}
		CodeGenerator.generateCode(operators, metadata);
	}
	

	private static void runQ5(String queryName, int numThreads, List<Integer> selections, boolean b) {
		List<Operator> operators = new ArrayList<Operator>();
		MetaData metadata = new MetaData();
		initQ5Indexes(metadata);
		initQ5Queries(metadata, queryName, numThreads);
		MetaQuery query = metadata.getQueryList().get(metadata.getCurrentQueryID());
		if (numThreads > 1) {
			initQ5OperatorsThreaded(operators, query, selections);
		}
		else {
			initQ5Operators(operators, query, selections);
		}
		CodeGenerator.generateCode(operators, metadata);
	}


	public static void main(String[] args) {

		List<Integer> selections1 = new ArrayList<Integer>();
		selections1.add(2981669);

		List<Integer> selections2 = new ArrayList<Integer>();
		selections2.add(10246893);

		List<Integer> selections3 = new ArrayList<Integer>();
		selections3.add(5450530);

		List<Integer> selections4 = new ArrayList<Integer>();
		selections4.add(1476432);

		List<Integer> selections5 = new ArrayList<Integer>();
		selections5.add(4945389);

		// Pubmed 
		//Q5 Optimal 
		runQ5("q5_opt_0threads_2981669", 1, selections1, true);
		runQ5("q5_opt_2threads_2981669", 2, selections1,  true);
		runQ5("q5_opt_4threads_2981669", 4, selections1,  true);
		runQ5("q5_opt_1threads_2981669", 10, selections1,  true);

		runQ5("q5_opt_0threads_10246893", 1, selections2, true);
		runQ5("q5_opt_2threads_10246893", 2, selections2,  true);
		runQ5("q5_opt_4threads_10246893", 4, selections2,  true);
		runQ5("q5_opt_1threads_10246893", 10, selections2,  true);		

		runQ5("q5_opt_0threads_5450530", 1, selections3, true);
		runQ5("q5_opt_2threads_5450530", 2, selections3,  true);
		runQ5("q5_opt_4threads_5450530", 4, selections3,  true);
		runQ5("q5_opt_1threads_5350530", 10, selections3,  true);

		runQ5("q5_opt_0threads_1476432", 1, selections4, true);
		runQ5("q5_opt_2threads_1476432", 2, selections4,  true);
		runQ5("q5_opt_4threads_1476432", 4, selections4,  true);
		runQ5("q5_opt_1threads_1476432", 10, selections4,  true);

		runQ5("q5_opt_0threads_4945389", 1, selections5, true);
		runQ5("q5_opt_2threads_4945389", 2, selections5,  true);
		runQ5("q5_opt_4threads_4945389", 4, selections5,  true);
		runQ5("q5_opt_1threads_4945389", 10, selections5,  true);

		//Q5 Array 
		runQ5("q5_array_0threads_2981669", 1, selections1, MetaData.ENCODING_UA);
		runQ5("q5_array_2threads_2981669", 2, selections1,  MetaData.ENCODING_UA);
		runQ5("q5_array_4threads_2981669", 4, selections1,  MetaData.ENCODING_UA);
		runQ5("q5_array_1threads_2981669", 10, selections1,  MetaData.ENCODING_UA);

		runQ5("q5_array_0threads_10246893", 1, selections2, MetaData.ENCODING_UA);
		runQ5("q5_array_2threads_10246893", 2, selections2,  MetaData.ENCODING_UA);
		runQ5("q5_array_4threads_10246893", 4, selections2,  MetaData.ENCODING_UA);
		runQ5("q5_array_1threads_10246893", 10, selections2,  MetaData.ENCODING_UA);		

		runQ5("q5_array_0threads_5450530", 1, selections3, MetaData.ENCODING_UA);
		runQ5("q5_array_2threads_5450530", 2, selections3,  MetaData.ENCODING_UA);
		runQ5("q5_array_4threads_5450530", 4, selections3,  MetaData.ENCODING_UA);
		runQ5("q5_array_1threads_5350530", 10, selections3,  MetaData.ENCODING_UA);

		runQ5("q5_array_0threads_1476432", 1, selections4, MetaData.ENCODING_UA);
		runQ5("q5_array_2threads_1476432", 2, selections4,  MetaData.ENCODING_UA);
		runQ5("q5_array_4threads_1476432", 4, selections4,  MetaData.ENCODING_UA);
		runQ5("q5_array_1threads_1476432", 10, selections4,  MetaData.ENCODING_UA);

		runQ5("q5_array_0threads_4945389", 1, selections5, MetaData.ENCODING_UA);
		runQ5("q5_array_2threads_4945389", 2, selections5,  MetaData.ENCODING_UA);
		runQ5("q5_array_4threads_4945389", 4, selections5,  MetaData.ENCODING_UA);
		runQ5("q5_array_1threads_4945389", 10, selections5,  MetaData.ENCODING_UA);

		//Q5 Optimal 
		runQ5("q5_bca_0threads_2981669", 1, selections1, MetaData.ENCODING_BCA);
		runQ5("q5_bca_2threads_2981669", 2, selections1,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_4threads_2981669", 4, selections1,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_1threads_2981669", 10, selections1,  MetaData.ENCODING_BCA);

		runQ5("q5_bca_0threads_10246893", 1, selections2, MetaData.ENCODING_BCA);
		runQ5("q5_bca_2threads_10246893", 2, selections2,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_4threads_10246893", 4, selections2,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_1threads_10246893", 10, selections2,  MetaData.ENCODING_BCA);		

		runQ5("q5_bca_0threads_5450530", 1, selections3, MetaData.ENCODING_BCA);
		runQ5("q5_bca_2threads_5450530", 2, selections3,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_4threads_5450530", 4, selections3,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_1threads_5350530", 10, selections3,  MetaData.ENCODING_BCA);

		runQ5("q5_bca_0threads_1476432", 1, selections4, MetaData.ENCODING_BCA);
		runQ5("q5_bca_2threads_1476432", 2, selections4,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_4threads_1476432", 4, selections4,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_1threads_1476432", 10, selections4,  MetaData.ENCODING_BCA);

		runQ5("q5_bca_0threads_4945389", 1, selections5, MetaData.ENCODING_BCA);
		runQ5("q5_bca_2threads_4945389", 2, selections5,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_4threads_4945389", 4, selections5,  MetaData.ENCODING_BCA);
		runQ5("q5_bca_1threads_4945389", 10, selections5,  MetaData.ENCODING_BCA);

		//Q5 Optimal 
		runQ5("q5_huff_0threads_2981669", 1, selections1, MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_2threads_2981669", 2, selections1,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_4threads_2981669", 4, selections1,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_1threads_2981669", 10, selections1,  MetaData.ENCODING_HUFFMAN);

		runQ5("q5_huff_0threads_10246893", 1, selections2, MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_2threads_10246893", 2, selections2,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_4threads_10246893", 4, selections2,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_1threads_10246893", 10, selections2,  MetaData.ENCODING_HUFFMAN);		

		runQ5("q5_huff_0threads_5450530", 1, selections3, MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_2threads_5450530", 2, selections3,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_4threads_5450530", 4, selections3,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_1threads_5350530", 10, selections3,  MetaData.ENCODING_HUFFMAN);

		runQ5("q5_huff_0threads_1476432", 1, selections4, MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_2threads_1476432", 2, selections4,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_4threads_1476432", 4, selections4,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_1threads_1476432", 10, selections4,  MetaData.ENCODING_HUFFMAN);

		runQ5("q5_huff_0threads_4945389", 1, selections5, MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_2threads_4945389", 2, selections5,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_4threads_4945389", 4, selections5,  MetaData.ENCODING_HUFFMAN);
		runQ5("q5_huff_1threads_4945389", 10, selections5,  MetaData.ENCODING_HUFFMAN);


		System.out.println("Done");
	}




}
