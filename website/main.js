$(document).ready(function(){

    $("#textFilter").on("keyup", function() {
        var needle = $(this).val().toLowerCase();
        $("#table tr").filter(function() {
            var haystack = $(this).text().toLowerCase();
            $(this).toggle(haystack.indexOf(needle) > -1);
        });
    });

    for (const instr of instructions) {
        $("table tbody").append(
            `<tr>` + 
                `<th scope="row">${instr.architecture}</th>` + 
                `<td><kbd>${instr.instruction}</kbd></td>` + 
                `<td>${instr.ascii}</td>` + 
                `<td><code>${instr.hex}</code></td>` + 
            `</tr>`
        );
    }
});