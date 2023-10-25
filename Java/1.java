class First {
  public static void main(String[] args) {
    String nome = "Vincenzo Emanuel Montesano Schettino Larcher de Almeida Gnomo";
    String[] nomes = nome.toUpperCase().split(" ");
    String citation;

    citation = nomes[nomes.length - 1] + ", ";
    for(int i = 0; i < nomes.length; i++) {
      if(i != nomes.length - 1) {
        citation = citation.concat(nomes[i].substring(0, 1) + ". ");
      }
    }
    System.out.println(citation);
  }
}