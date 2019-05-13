class OrionModule {
};

class AltairModule {
public:
    /* Constructor accepts an OrionModule representing the Orion
    * spacecraft this Altair is associated with, then sets up
    * parentModule to point to that OrionModule.
    */
    AltairModule(OrionModule* owner);
/* ... */
private:
    OrionModule* const parentModule;
};

AltairModule::AltairModule(OrionModule* owner): parentModule(owner) {}

int main () {
    OrionModule o;
    AltairModule a(&o);

    return 0;
}