package fr.alexisc.webscience;

import java.io.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Main Application
 * <p>
 * It's purpose is to
 */
public class App {

    public static final String CORPUSES_PATH = "src/main/resources/corpuses/";
    public static final String CORPUSES_ANNOTATED_PATH = "src/main/resources/corpuses/annotated/";
    public static final String ENTITY_LIST_PATH = "src/main/resources/entity_list.txt";

    public static void main(String[] args) {

        File annotated = new File(CORPUSES_ANNOTATED_PATH);
        if (!annotated.exists()) {
            annotated.mkdirs();
        }

        Map<String, URI> uriMap = getURIMap();

        getCorpuses().forEach(corpus -> {
            String entityName = corpus.getName().split("\\.")[0];
            Entity entity = new Entity(uriMap.get(entityName), corpus);

            System.out.println("Processing `" + entityName + "` ...");

            Annotator annotator = new Annotator(entity);

            try {
                System.out.println("Annotating the text ...");
                annotator.annotate();
                System.out.println(entityName + " annotated.");
                String hasDateTriple = annotator.getBirthDateTriple(entity);
                List<String> typeTriple = annotator.getTypeTriples(entity);

                if(hasDateTriple != null){
                    System.out.println("Triple <hasDate> found : " + hasDateTriple);
                } else {
                    System.out.println("No triple <hasDate> found.");
                }

                if(!typeTriple.isEmpty()){
                    typeTriple.forEach(triple -> System.out.println("Triple <type> found : " + typeTriple));
                } else {
                    System.out.println("No triple <type> found.");
                }

            } catch (IOException e) {
                e.printStackTrace();
            }


        });
    }


    private static List<File> getCorpuses() {

        File folder = new File(CORPUSES_PATH);
        File[] files = folder.listFiles();

        if (files == null) {
            return Collections.emptyList();
        }
        return Arrays.stream(files).filter(File::isFile).collect(Collectors.toList());
    }

    private static Map<String, URI> getURIMap() {

        Map<String, URI> uriMap = new HashMap<>();
        try {
            BufferedReader br = new BufferedReader(new FileReader(ENTITY_LIST_PATH));

            String line;
            while ((line = br.readLine()) != null) {
                uriMap.put(line.split("/")[4], new URI(line));
            }

            br.close();
        } catch (FileNotFoundException e) {
            System.err.println("The entity file was not found.");
        } catch (IOException e) {
            System.err.println("The entity couldn't be read.");
        } catch (URISyntaxException e) {
            System.err.println("The entity URI was malformed.");
        }

        return uriMap;
    }
}
