$(document).ready(function(){

    $("#textFilter").on("keyup", function() {
        var needle = $(this).val().toLowerCase();
        $("#table tr").filter(function() {
            var haystack = $(this).text().toLowerCase();
            $(this).toggle(haystack.indexOf(needle) > -1);
        });
    });
});